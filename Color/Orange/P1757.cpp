// https://www.luogu.com.cn/problem/P175
// dp,分组背包

#include <bits/stdc++.h>
using namespace std;
int V, n, t;
int x;
int zu[205][205];       // 第i组第j件物品的下标
int w[10001], v[10001]; // w代表重量，v代表价值
int zu_num[10001];      // 代表每组的物品数量
int dp[10001];
int main()
{
    int i, j, k;
    cin >> V >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> x;
        t = max(t, x);
        zu_num[x]++;
        zu[x][zu_num[x]] = i;
    }
    for (i = 1; i <= t; i++)
    {
        for (j = V; j >= 0; j--)
        {
            for (k = 1; k <= zu_num[i]; k++)
            {
                if (j >= w[zu[i][k]])
                {
                    dp[j] = max(dp[j], dp[j - w[zu[i][k]]] + v[zu[i][k]]);
                }
            }
        }
    }
    cout << dp[V];
    return 0;
}
