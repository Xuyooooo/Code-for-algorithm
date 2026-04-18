// https://www.luogu.com.cn/problem/P1433
// dfs，优化

//===============普通dfs(会超时)==============
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;
// double locationx[16];
// double locationy[16];
// bool vis[16];
// double ans = 1e3;
// double nowx = 0, nowy = 0;
// int n;
// void dfs(double x, double y, double cur)
// {
//     if (cur >= ans)
//         return;
//     bool found = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             vis[i] = 1;
//             dfs(locationx[i], locationy[i], cur + sqrt(pow(locationx[i] - x, 2) + pow(locationy[i] - y, 2)));
//             vis[i] = 0;
//             found = 0;
//         }
//     }
//     if (found)
//         ans = min(ans, cur);
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> locationx[i] >> locationy[i];
//     }
//     dfs(nowx, nowy, 0);
//     cout << fixed << setprecision(2) << ans << '\n';
//     return 0;
// }

//============1基础上剪枝优化(依旧超时)=============
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;

// double x[16], y[16];
// bool vis[16];
// double dis[16][16]; // 预处理距离：i 到 j 的距离
// double ans = 1e9;
// int n;

// // 当前在 u 号点，已走长度 len，访问了 cnt 个奶酪
// void dfs(int u, double len, int cnt)
// {
//     // 剪枝：当前长度已经比答案大，直接退出
//     if (len >= ans)
//         return;
//     // 所有点都访问完了
//     if (cnt == n)
//     {
//         ans = min(ans, len);
//         return;
//     }
//     for (int i = 1; i <= n; ++i)
//     {
//         if (!vis[i])
//         {
//             vis[i] = 1;
//             dfs(i, len + dis[u][i], cnt + 1);
//             vis[i] = 0;
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> x[i] >> y[i];
//     }
//     // 预处理：起点(0,0) 到每个点 i 的距离
//     for (int i = 1; i <= n; ++i)
//     {
//         dis[0][i] = sqrt(x[i] * x[i] + y[i] * y[i]);
//     }
//     // 预处理：点 i 到点 j 的距离
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             double dx = x[i] - x[j];
//             double dy = y[i] - y[j];
//             dis[i][j] = sqrt(dx * dx + dy * dy);
//         }
//     }
//     dfs(0, 0.0, 0); // 从 0 号虚拟起点出发
//     cout << fixed << setprecision(2) << ans << endl;
//     return 0;
// }

//================状态压缩DP(标准解法)===============
// n<=12时，暴力dfs能过
// n>=13，必须用状压dfs
// 复杂度为n方*2的n次方

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAXN = 16;
const int MAXSTA = 1 << 16;

double x[MAXN], y[MAXN];
double dis[MAXN][MAXN];
// dp[sta][u] = 访问状态sta，最后停在u点的最短距离
double dp[MAXSTA][MAXN];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // 预处理距离：0 是起点 (0,0)
    for (int i = 1; i <= n; i++)
    {
        dis[0][i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            dis[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // 初始化 DP 为极大值
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 1e18;
        }
    }

    // 初始状态：只访问了第 i 个点，从起点过去
    for (int i = 1; i <= n; i++)
    {
        dp[1 << (i - 1)][i] = dis[0][i];
    }

    // 枚举所有状态
    for (int sta = 0; sta < (1 << n); sta++)
    {
        // 枚举当前所在点 u
        for (int u = 1; u <= n; u++)
        {
            if (!(sta & (1 << (u - 1))))
                continue; // 没访问过 u 跳过
            // 枚举下一个点 v
            for (int v = 1; v <= n; v++)
            {
                if (sta & (1 << (v - 1)))
                    continue; // 已经访问过跳过
                int newsta = sta | (1 << (v - 1));
                dp[newsta][v] = min(dp[newsta][v], dp[sta][u] + dis[u][v]);
            }
        }
    }

    // 答案：所有点都访问完的最小值
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
