// https://www.luogu.com.cn/problem/P1962
// 斐波那契数列。-----矩阵快速幂加速递推做法

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll Mod = 1e9 + 7;
ll n;
class matrix
{
public:
    ll row, col;
    vector<vector<ll>> mat;
    matrix(int n = 3) : row(n), col(n), mat(n + 1, vector<ll>(n + 1, 0))
    {
    }
    static matrix init(int n = 3)
    {
        matrix res(n);
        for (int i = 1; i <= n; i++)
        {
            res.mat[i][i] = 1; // 单位矩阵初始化
        }
        return res;
    }
    matrix operator*(const matrix &other) const
    {
        matrix res(row);
        for (int i = 1; i <= row; i++)
        {
            for (int k = 1; k <= col; k++)
            {
                if (mat[i][k] == 0)
                    continue;
                for (int j = 1; j <= other.col; j++)
                {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % Mod;
                }
            }
        }
        return res;
    }
};
matrix fpow(matrix x, ll n)
{
    matrix res = matrix::init(x.row);
    while (n)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n;
    matrix a;
    a.mat[1][1] = a.mat[1][3] = a.mat[2][1] = a.mat[3][2] = 1;
    matrix res = fpow(a, n);
    cout << res.mat[2][1] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
