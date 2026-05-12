// https://www.luogu.com.cn/problem/P2758

//=============================DP===================
// #include <iostream>
// #include <string>
// const int N = 2001;
// int dp[N][N]; // 表示从a的前i个字符转换到b的前i个字符所需要的操作步骤
// using namespace std;
// int m, n;
// void init()
// {
//     for (int i = 1; i <= n; i++)
//         dp[0][i] = i;
//     for (int i = 1; i <= m; i++)
//         dp[i][0] = i;
// }
// int main()
// {
//     string a, b;
//     cin >> a >> b;
//     m = a.size(), n = b.size();
//     init();
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (a[i - 1] == b[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//             {
//                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//             }
//         }
//     }
//     cout << dp[m][n] << '\n';
//     return 0;
// }

//=====================滚动数组优化==============
#include <iostream>
#include <string>
using namespace std;

const int N = 2001;
int dp[N];

int main()
{
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();

    // 初始化：dp[0][j]
    for (int j = 0; j <= n; j++)
        dp[j] = j;

    for (int i = 1; i <= m; i++)
    {
        int pre = dp[0]; // dp[i-1][0]
        dp[0] = i;       // dp[i][0]

        for (int j = 1; j <= n; j++)
        {
            int temp = dp[j]; // 暂存 dp[i-1][j]
            if (a[i - 1] == b[j - 1])
                dp[j] = pre;
            else
                dp[j] = min(pre, min(dp[j], dp[j - 1])) + 1;

            pre = temp; // 更新 dp[i-1][j-1]
        }
    }

    cout << dp[n] << endl;
    return 0;
}