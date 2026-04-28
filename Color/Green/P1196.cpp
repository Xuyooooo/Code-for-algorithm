// https://www.luogu.com.cn/problem/P1196

// 带权并查集

#include <iostream>
#include <cmath>
using namespace std;
const int N = 3e4 + 10;
int fa[N], front[N], num[N], T, n = 30000; // front[i]表示飞船i与其所在列队头(根节点)的距离，num[i]表示第i列的飞船数量
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        num[i] = 1;
        front[i] = 0;
    }
}
int query(int x)
{
    if (x != fa[x])
    {
        int t = fa[x];
        fa[x] = query(fa[x]);
        front[x] += front[t];
    }
    return fa[x];
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    fa[a] = b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char opi;
    int x, y;
    cin >> T;
    init();
    while (T--)
    {
        cin >> opi >> x >> y;
        int a = query(x), b = query(y);
        if (opi == 'M')
        {
            front[a] += num[b];
            num[b] += num[a];
            num[a] = 0;
            fa[a] = b;
        }
        else if (opi == 'C')
        {
            if (a != b)
                cout << "-1" << '\n';
            else
                cout << abs(front[x] - front[y]) - 1 << '\n';
        }
    }
    return 0;
}