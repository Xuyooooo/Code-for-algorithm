// https://www.luogu.com.cn/problem/P3368

#include <iostream>
using namespace std;
const int N = 5e5 + 10;
long long tree[N];
int n, m;
int lowbit(int x)
{
    return (x & -x);
}
void add(int l, int d)
{
    for (int i = l; i <= n; i += lowbit(i))
    {
        tree[i] += d;
    }
}
void range_change(int l, int r, int d)
{
    add(l, d);
    add(r + 1, -d);
}
long long query(int x)
{
    long long res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        res += tree[i];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        range_change(i, i, a);
    }
    for (int i = 1; i <= m; i++)
    {
        int opi;
        cin >> opi;
        if (opi == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            range_change(x, y, k);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(x) << '\n';
        }
    }
    return 0;
}