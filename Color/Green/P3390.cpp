// https://www.luogu.com.cn/problem/P3390
//  矩阵快速幂模板

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll Mod = 1e9 + 7;
int n;
ll k;
class matrix
{
public:
    int row, col;
    vector<vector<ll>> mat;
    matrix(int r, int c) : row(r), col(c), mat(r + 1, vector<ll>(c + 1, 0))
    {
    }
    static matrix identity(int n)
    {
        matrix res(n + 1, n + 1);
        for (int i = 1; i <= n; i++)
        {
            res.mat[i][i] = 1;
        }
        return res;
    }
    matrix operator*(const matrix &other) const
    {
        matrix res(row, other.col);
        for (int i = 1; i <= row; i++)
        {
            for (int k = 1; k <= col; k++)
            {
                if (mat[i][k] == 0)
                    continue;
                for (int j = 1; j <= other.col; j++)
                {
                    // res.mat[i][j] += mat[i][k] * other.mat[k][j];
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % Mod;
                }
            }
        }
        return res;
    }
};
matrix matrix_fpow(matrix a, ll n)
{
    matrix res = matrix::identity(a.row);
    while (n > 0)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n >> k;
    if (!k)
    {
        matrix res = matrix::identity(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << res.mat[i][j] << ' ';
            cout << endl;
        }
    }
    else
    {
        matrix a(n, n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> a.mat[i][j];
        }
        matrix res = matrix_fpow(a, k);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << res.mat[i][j] << ' ';
            cout << endl;
        }
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