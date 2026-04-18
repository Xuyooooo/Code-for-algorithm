// https://www.luogu.com.cn/problem/P1115
// 最大子段和
// 前缀和，dp优化

//=========逻辑推理(dp优化)===========
// #include <iostream>
// const int N = 2e5 + 5;
// int num[N];
// using namespace std;
// int main()
// {
//     int n, maxn, sum;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> num[i];
//     }
//     maxn = num[1], sum = num[1];
//     for (int i = 2; i <= n; i++)
//     {
//         sum += num[i];
//         if (sum > maxn)
//             maxn = sum;
//         if (sum <= 0)
//             sum = 0;
//     }
//     cout << maxn;
//     return 0;
// }

//===============前缀和==============有问题
#include <iostream>
const int N = 2e5 + 10;
int sum[N];
using namespace std;
int main()
{
    int n, max = 0, pre = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    cout << sum[max] - sum[min] << '\n';
    return 0;
}

//==================DP===============
// #include <iostream>
// #include <algorithm>
// const int N = 2e5 + 10;
// int dp[N];
// using namespace std;
// int main()
// {
//     int n, maxn = -1e4;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int temp;
//         cin >> temp;
//         dp[i] = max(dp[i - 1] + temp, temp);
//         maxn = max(maxn, dp[i]);
//     }
//     cout << maxn << '\n';
//     return 0;
// }