// https://www.luogu.com.cn/problem/P1190
// 小顶堆。模拟

//==================堆==============
#include <bits/stdc++.h>
using namespace std;
int n, m, w;
int t;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &w);
        q.push(w);
    }
    for (int i = 1; i <= n - m; i++)
    {
        t = q.top();
        q.pop();
        scanf("%d", &w);
        q.push(t + w);
    }
    while (q.size() > 1)
        q.pop();
    printf("%d", q.top());
    return 0;
}
// #include <iostream>
// using namespace std;
// int s[11000], ans;
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> s[i];
//     int t = m + 1;
//     while (t <= n + m)
//     {
//         for (int i = 1; i <= m; i++)
//         {
//             s[i]--;
//             if (s[i] == 0)
//             {
//                 s[i] = s[t];
//                 t++;
//             }
//         }
//         ans++;
//     }
//     cout << ans;
//     return 0;
// }
