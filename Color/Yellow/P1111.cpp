// https://www.luogu.com.cn/problem/P1111

// 贪心，并查集

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
int n, m, judge;
class vill
{
public:
    int u, v, t;
} village[N];
bool com(vill a, vill b)
{
    return a.t <= b.t;
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int query(int x)
{
    if (x != fa[x])
    {
        fa[x] = query(fa[x]);
    }
    return fa[x];
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    if (a != b)
    {
        fa[a] = fa[b];
        judge--;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    judge = n;
    init();
    for (int i = 1; i <= m; i++)
        cin >> village[i].u >> village[i].v >> village[i].t;
    sort(village + 1, village + m + 1, com);
    for (int i = 1; i <= m; i++)
    {
        merge(village[i].u, village[i].v);
        if (judge == 1)
        {
            cout << village[i].t << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}