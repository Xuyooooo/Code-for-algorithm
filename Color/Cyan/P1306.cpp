// https://www.luogu.com.cn/problem/P1306

// 在斐波那契数列中，存在关系式:  gcd( F(n), F(m) )  =  F( gcd(n,m )

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll Mod = 1e8;
int n, m;
class matrix
{
public:
    ll row, col;
    vector<vector<ll>> mat;
    matrix(int x = 2, int y = 2) : row(x), col(y), mat(x + 1, vector<ll>(y + 1, 0))
    {
    }
    static matrix init(int x = 2, int y = 2)
    {
        matrix res(x, y);
        for (int i = 1; i <= x; i++)
        {
            res.mat[i][i] = 1; // 单位矩阵初始化
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
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % Mod;
                }
            }
        }
        return res;
    }
};
matrix fpow(matrix x, ll n)
{
    matrix res = matrix::init(x.row, x.col);
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
    cin >> n >> m;
    matrix A, orig(2, 1);
    A.mat[1][1] = A.mat[1][2] = A.mat[2][1] = 1;
    orig.mat[1][1] = orig.mat[2][1] = 1;
    int mid = __gcd(n, m);
    if (mid == 1)
    {
        cout << 1 << endl;
        return;
    }
    matrix res = fpow(A, mid - 2) * orig;
    cout << res.mat[1][1] << endl;
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