// https://www.luogu.com.cn/problem/P2097

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int fa[N];
int n, m, p, q, judge;

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int query(int x)
{
    if (fa[x] != x)
        fa[x] = query(fa[x]);
    return fa[x];
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    if (a != b)
    {
        judge--;
        fa[a] = fa[b];
    }
}
int main()
{
    cin >> n >> m;
    judge = n;
    init();
    for (int i = 1; i <= m; i++)
    {
        cin >> p >> q;
        merge(p, q);
    }
    cout << judge << '\n';
    return 0;
}