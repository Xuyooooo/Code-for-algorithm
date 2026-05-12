// https://www.luogu.com.cn/problem/P2078

// 并查集

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10001;

int fa_a[N], num_a[N];
int fa_b[N], num_b[N];
int n, m, p, q, x, y;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa_a[i] = i;
        num_a[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        fa_b[i] = i;
        num_b[i] = 1;
    }
}
int query1(int x)
{
    if (fa_a[x] != x)
    {
        fa_a[x] = query1(fa_a[x]);
    }
    return fa_a[x];
}
int query2(int x)
{
    if (fa_b[x] != x)
    {
        fa_b[x] = query2(fa_b[x]);
    }
    return fa_b[x];
}
void merge1(int x, int y)
{
    int a = query1(x);
    int b = query1(y);
    if (a != b)
    {
        fa_a[a] = fa_a[b];
        num_a[b] += num_a[a];
    }
}
void merge2(int x, int y)
{
    int a = query2(x);
    int b = query2(y);
    if (a != b)
    {
        fa_b[a] = fa_b[b];
        num_b[b] += num_b[a];
    }
}
int main()
{
    cin >> n >> m >> p >> q;
    init();
    for (int i = 1; i <= p; i++)
    {
        cin >> x >> y;
        merge1(x, y);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        merge2(-x, -y);
    }
    cout << min(num_a[query1(1)], num_b[query2(1)]) << '\n';
    return 0;
}