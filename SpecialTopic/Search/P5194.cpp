// https://www.luogu.com.cn/problem/P5194
// 搜搜，dfs，dp，dfs优化

//=============正序DFS(部分数据点超时)=================
// #include <iostream>
// using namespace std;
// const int N = 1010;
// int weight[N];
// int n, maxn;
// long long ans, c;
// void dfs(int now, long long cur)
// {
//     if (cur > c)
//         return;
//     if (now > maxn)
//     {
//         if (ans < cur)
//             ans = cur;
//         return;
//     }
//     dfs(now + 1, cur);
//     dfs(now + 1, cur + weight[now]);
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> c;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> weight[i];
//         if (weight[i] <= c)
//             maxn = i;
//     }
//     if (weight[maxn] == c)
//     {
//         cout << c << '\n';
//         return 0;
//     }
//     dfs(1, 0);
//     cout << ans << '\n';
//     return 0;
// }

//====================剪枝优化dfs==============
// 此题不可以采用背包做法，因为C过大
// 虽然N<=1000，但每一个砝码至少等于前面两个砝码质量和（斐波那契），即n<=30
// 此题因为求最大值，则应该采用逆序搜索

#include <iostream>
using namespace std;
const int N = 1010;
int weight[N];
long long sum[N];
int n, maxn;
long long c, ans;
void dfs(int now, long long cur)
{
    if (cur + sum[now] <= ans)
        return;
    ans = max(ans, cur);
    for (int i = now; i; i--)
    {
        if (cur + weight[i] <= c)
            dfs(i - 1, cur + weight[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        if (weight[i] <= c)
        {
            maxn = i;
            sum[i] = sum[i - 1] + weight[i];
        }
    }
    if (weight[maxn] == c)
    {
        cout << c << '\n';
        return 0;
    }
    dfs(maxn, 0);
    cout << ans << '\n';
    return 0;
}