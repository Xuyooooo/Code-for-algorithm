// https://www.luogu.com.cn/problem/P3367
// 并查集模板
#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
        a[i] = i;
}
int query(int x)
{
    if (x != a[x])
        a[x] = query(a[x]);
    return a[x];
}
void merge(int x, int y)
{
    int a1 = query(x);
    int b1 = query(y);
    if (a1 != b1)
        a[a1] = a[b1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
        {
            merge(x, y);
        }
        else
        {
            x = query(x);
            y = query(y);
            if (x != y)
                cout << 'N' << '\n';
            else
                cout << 'Y' << '\n';
        }
    }
    return 0;
}