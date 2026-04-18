// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int N = 100;
// ll n, sum[N];
// //结果符合Cantala数(卡特兰数)
// int main()
// {
//     cin >> n;
//     sum[1] = 1;
//     for (int i = 2; i <= 18; i++)
//     {
//         sum[i] = sum[i - 1] * 2 * (2 * i - 1) / (i + 1);
//         // cout<<sum[i]<<"\n";
//     }
//     cout << sum[n];
//     return 0;
// }
// 递归，用DP改进
#include <bits/stdc++.h>
using namespace std;
int f[20][20], n;
int main()
{
    cin >> n;
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            if (!x)
                f[x][y] = 1;
            else if (!y)
                f[x][y] = f[x - 1][y + 1];
            else
                f[x][y] = f[x - 1][y + 1] + f[x][y - 1];
        }
    }
    cout << f[n][0];
}
