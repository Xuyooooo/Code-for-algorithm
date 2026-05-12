// https://www.luogu.com.cn/problem/P1776

// 多重背包

//===============将多个物品分为每个独立的物品(TLE)==============
// #include <iostream>
// using namespace std;
// const int N = 1e5 + 5;
// int w[N], v[N];
// int n, V, a, b, c;
// int dp[40005];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int size = 1;
//     cin >> n >> V;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a >> b >> c;
//         while (c--)
//         {
//             v[size] = a;
//             w[size] = b;
//             size++;
//         }
//     }
//     for (int i = 1; i < size; i++)
//     {
//         for (int j = V; j >= 0; j--)
//         {
//             if (j >= w[i])
//                 dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
//         }
//     }
//     cout << dp[V] << '\n';
//     return 0;
// }

//===========直接求解(第i间物品装多少件来讨论)
// #include <iostream>
// using namespace std;
// const int N = 1e5 + 10;
// int n, C, dp[N];
// int w[N], c[N], m[N];
// int main()
// {
//     cin >> n >> C;
//     for (int i = 1; i <= n; i++)
//         cin >> w[i] >> c[i] >> m[i];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = C; j >= c[i]; j--)
//         {
//             for (int k = 1; k <= m[i] && k * c[i] <= j; k++)
//             {
//                 dp[j] = max(dp[j], dp[j - k * c[i]] + k * w[i]);
//             }
//         }
//     }
//     cout << dp[C] << '\n';
//     return 0;
// }

//==========二进制拆分优化==================
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, C, dp[N];
int w[N], c[N], m[N];
int new_n;
int new_w[N], new_c[N], new_m[N];
int main()
{
    cin >> n >> C;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> c[i] >> m[i];
    new_n = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m[i]; j <<= 1)
        {
            m[i] -= j;
            new_c[++new_n] = j * c[i];
            new_w[new_n] = j * w[i];
        }
        if (m[i])
        {
            new_c[++new_n] = m[i] * c[i];
            new_w[new_n] = m[i] * w[i];
        }
    }
    for (int i = 1; i <= new_n; i++)
    {
        for (int j = C; j >= new_c[i]; j--)
            dp[j] = max(dp[j], dp[j - new_c[i]] + new_w[i]);
    }
    cout << dp[C] << '\n';
    return 0;
}