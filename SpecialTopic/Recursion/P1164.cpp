
// #include <iostream>
// using namespace std;
// const int N = 110;
// int menu[N];
// int n, m;
// int ans = 0;

// // DFS 函数
// void dfs(int p, int cur)
// {
//     if (cur == m)
//     {
//         ans++;
//         return;
//     }
//     if (cur > m || p > n)
//         return;

//     // 选当前菜
//     dfs(p + 1, cur + menu[p]);
//     // 不选当前菜
//     dfs(p + 1, cur);
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> menu[i];
//     dfs(1, 0);           // 从第一个菜开始
//     cout << ans << endl; // 输出总组合数
//     return 0;
// }
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[101], f[101][10001] = {0};
// DP
// 状态转移方程f[i][j]为用前i道菜用光j元钱的办法总数
// （1）if(j==第i道菜的价格)f[i][j]=f[i-1][j]+1;
// （2）if(j > 第i道菜的价格) f[i][j] = f[i - 1][j] + f[i - 1][j - 第i道菜的价格];
// （3）if(j < 第i道菜的价格) f[i][j] = f[i - 1][j]
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (j == a[i])
                f[i][j] = f[i - 1][j] + 1;
            if (j > a[i])
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            if (j < a[i])
                f[i][j] = f[i - 1][j];
        }
    cout << f[n][m];
    return 0;
}
