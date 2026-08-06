#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 101;
ll A[N][N], B[N][N], C[N][N];
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
            cin >> B[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int l = 1; l <= m; l++)
                C[i][j] += A[i][l] * B[l][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}