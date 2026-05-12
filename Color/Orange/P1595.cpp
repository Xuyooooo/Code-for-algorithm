// https://www.luogu.com.cn/problem/P1595
// 错排问题，状态压缩dp，递推

//================递推============
// #include <iostream>
// using namespace std;
// const int N = 21;
// long long dp[N];
// int main()
// {
//     int n;
//     cin >> n;
//     dp[1] = 0;
//     dp[2] = 1;
//     for (int i = 3; i <= n; i++)
//         dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
//     cout << dp[n] << '\n';
//     return 0;
// }

//==================状态压缩DP(压缩空间版本)========
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// long long dp[1 << 21];
// int cal_now(int x)
// {
//     int num = 0;
//     while (x)
//     {
//         if (x & 1)
//             num++;
//         x >>= 1;
//     }
//     return num;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     dp[0] = 1;
//     for (int state=0; state < (1 << n); ++state)
//     {
//         if (dp[state] == 0)
//             continue;
//         int cur = cal_now(state);
//         for (int j = 0; j < n; ++j)
//         {
//             if (!((state >> j) & 1) && j != cur)
//             {
//                 dp[state | (1 << j)] += dp[state];
//             }
//         }
//     }
//     cout << dp[(1 << n) - 1] << '\n';
//     return 0;
// }

//==============状态压缩DP(普通版本)===============

#include <iostream>
#include <vector>

using namespace std;

long long dp[21][1 << 20];

int main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    // 枚举放入第i封信时的状态
    for (int i = 1; i <= n; i++)
    {
        for (int state = 0; state < (1 << n); ++state)
        {
            if (dp[i - 1][state] == 0)
                continue;
            // 尝试给当前的第i封信找一个信封j
            for (int j = 0; j < n; ++j)
            {
                if (!((state >> j) & 1) && j != (i - 1))
                {
                    int next = state | (1 << j);
                    dp[i][next] += dp[i - 1][state];
                }
            }
        }
    }
    cout << dp[n][(1 << n) - 1] << '\n';
    return 0;
}