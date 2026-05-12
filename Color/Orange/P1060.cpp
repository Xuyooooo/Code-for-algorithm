// https://www.luogu.com.cn/problem/P1060

// 01背包
#include <iostream>

using namespace std;

const int N = 25;

int v[N], p[N];
int n, m;
int dp[30005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> v[i] >> p[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}