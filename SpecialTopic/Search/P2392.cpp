// https://www.luogu.com.cn/problem/P2392
// 搜索、深搜、DP

//==============这是本人想法，过于天真，错误=============
// #include <iostream>
// #include <algorithm>
// const int N = 21;
// int a[5][N];
// int ans = 0;

// using namespace std;

// int main()
// {
//     int s1, s2, s3, s4;
//     cin >> s1 >> s2 >> s3 >> s4;
//     for (int i = 1; i <= s1; i++)
//         cin >> a[1][i];
//     sort(a[1] + 1, a[1] + s1 + 1);
//     for (int i = 1; i <= s2; i++)
//         cin >> a[2][i];
//     sort(a[2] + 1, a[2] + s2 + 1);
//     for (int i = 1; i <= s3; i++)
//         cin >> a[3][i];
//     sort(a[3] + 1, a[3] + s3 + 1);
//     for (int i = 1; i <= s4; i++)
//         cin >> a[4][i];
//     sort(a[4] + 1, a[4] + s4 + 1);
//     for (int i = s1; i >= 1; i -= 2)
//     {
//         ans += a[1][i];
//         if (i - 2 >= 1)
//             a[1][i - 2] -= (a[1][i] - a[1][i - 1]);
//     }
//     for (int i = s2; i >= 1; i -= 2)
//     {
//         ans += a[2][i];
//         if (i - 2 >= 1)
//             a[2][i - 2] -= (a[2][i] - a[2][i - 1]);
//     }
//     for (int i = s3; i >= 1; i -= 2)
//     {
//         ans += a[3][i];
//         if (i - 2 >= 1)
//             a[3][i - 2] -= (a[3][i] - a[3][i - 1]);
//     }
//     for (int i = s4; i >= 1; i -= 2)
//     {
//         ans += a[4][i];
//         if (i - 2 >= 1)
//             a[4][i - 2] -= (a[4][i] - a[4][i - 1]);
//     }
//     cout << ans << '\n';
//     return 0;
// }

//================深搜代码(数据较水，依然能过)===============
#include <bits/stdc++.h>
using namespace std;
int Left, Right, minn, ans;
int s[5];
int a[21][5];
void search(int x, int y)
{
    if (x > s[y])
    {
        minn = min(minn, max(Left, Right));
        return;
    }
    Left += a[x][y];
    search(x + 1, y);
    Left -= a[x][y];
    Right += a[x][y];
    search(x + 1, y);
    Right -= a[x][y]; // 毫无技巧的搜索回溯
}
int main()
{
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4; i++)
    { // 减少码量
        Left = Right = 0;
        minn = 19260817;
        for (int j = 1; j <= s[i]; j++)
            cin >> a[j][i];
        search(1, i);
        ans += minn;
    }
    cout << ans;
    return 0;
}

//=================DP代码=============
// 思路：花费最少时间至少为总时间的一半，即左右脑子至少有一个时间大于sum/2
// 控制一个脑子时间小于等于sum/2，则另一个脑子时间即为解
// #include <bits/stdc++.h>
// using namespace std;
// int a[5], i, j, k, sum, t, homework[21], dp[2501];
// int main()
// {
//     for (i = 1; i <= 4; i++)
//         cin >> a[i];
//     for (i = 1; i <= 4; i++)
//     {
//         sum = 0;
//         for (j = 1; j <= a[i]; j++)
//         {
//             cin >> homework[j]; // 输入
//             sum += homework[j];
//         } // 总时间累加
//         for (j = 1; j <= a[i]; j++)
//             for (k = sum / 2; k >= homework[j]; k--)                   // 只要是总和的一半
//                 dp[k] = max(dp[k], dp[k - homework[j]] + homework[j]); // 01背包，这里求的是背包容量最大是k时所容纳价值最大值
//         t += sum - dp[sum / 2];                                        // 累加为另一个脑子
//         for (j = 1; j <= sum / 2; j++)
//             dp[j] = 0; // 清零
//     }
//     cout << t; // 输出
//     return 0;
// }
