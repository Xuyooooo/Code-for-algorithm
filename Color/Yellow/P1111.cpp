// https://www.luogu.com.cn/problem/P1111

#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int village[N];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
        village[i] = i;
}
int query(int x)
{
    if (x != village[x])
        village[x] = query(village[x]);
    return village[x];
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    if (a != b)
        village[a] = village[b];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        merge(x, y);
    }
}