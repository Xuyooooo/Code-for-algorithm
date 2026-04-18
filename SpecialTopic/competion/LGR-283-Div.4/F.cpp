

#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int a[50001][N];
int n, m, q;
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[0][i];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i][x] = y;
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        while (!a[u][v])
        {
            u--;
        }
        cout << a[u][v] << '\n';
    }
    return 0;
}