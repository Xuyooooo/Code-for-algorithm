// https://www.luogu.com.cn/problem/P1048
// 01背包
#include <iostream>
using namespace std;
int w[105], val[105];
int dp[1005]; // int dp[105][1005]; // 将前i个药品在j时间内采摘的最大收益
int main()
{
    int t, m, res = -1;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> val[i];
    }
    // for (int i = 1; i <= m; i++)
    //     for (int j = t; j >= 0; j--)
    //     {
    //         if (j >= w[i])
    //         {
    //             dp[i][j] = max(dp[i - 1][j - w[i]] + val[i], dp[i - 1][j]);
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= val[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
        }
    }
    cout << dp[t] << '\n'; // cout << dp[m][t] << '\n';
    return 0;
}
