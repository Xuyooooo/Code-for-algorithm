// // https://www.luogu.com.cn/problem/P1591
// // 洛谷p1591阶乘数码，模拟大数相乘

// #include <iostream>
// #include <string>
// const int N = 1010;
// using namespace std;
// string jiecheng[N];
// int t, n, a;
// string multipfy(int n)
// {
//     int carry = 0;
//     if (!jiecheng[n - 1].empty())
//     {
//         int size = jiecheng[n - 1].size();
//         for (int i = size - 1; i >= 0; i--)
//         {
//             int ans = (jiecheng[n - 1][i] - '0') * n + carry;
//             jiecheng[n] = (char)(ans % 10 + '0') + jiecheng[n];
//             carry = ans / 10;
//         }
//         if(!carry)
//         jiecheng[n]=(char)(carry+'0')+jiecheng[n];
//         return jiecheng[n];
//     }
//     else
//     {
//         for(int i=1;i<=n;i++)
//         {

//         }

//     }
// }
// int check_num(string ans, int goal)
// {
//     int num = 0;
//     for (int i = 0; i < ans.size(); i++)
//     {
//         if (ans[i] == goal + '0')
//             num++;
//     }
//     return num;
// }
// int main()
// {
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         cin >> n >> a;
//         string ans = multipfy(n);
//         cout << check_num(ans, a) << '\n';
//     }
//     return 0;
// }

//==========整形数组================
#include <bits/stdc++.h>
using namespace std;
long long t, a[10009];
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long n, k, ws = 1, ans = 0;
        cin >> n >> k;
        a[1] = 1;
        for (int j = 2; j <= 10000; j++)
            a[j] = 0;
        for (int j = 2; j <= n; j++)
        {
            for (int l = 1; l <= ws; l++)
            {
                a[l] *= j;
            }
            for (int l = 1;; l++)
            {
                a[l + 1] += a[l] / 10;
                a[l] %= 10;
                if (l >= ws && a[l + 1] == 0)
                {
                    ws = l;
                    break;
                }
            }
        }
        for (int j = 1; j <= ws; j++)
        {
            if (a[j] == k)
                ans++;
        }
        cout << ans << endl;
    }
}
