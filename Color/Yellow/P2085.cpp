// // https://www.luogu.com.cn/problem/P2085

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
long long n, m;
long long cal(long long x, long long a, long long b, long long c)
{
    long long res = x * x * a + b * x + c;
    return res;
}
int main()
{
    stack<long long> out;
    priority_queue<long long> hp;
    cin >> n >> m;
    vector<long long> A(n + 1), B(n + 1), C(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }
    for (long long i = 1; i <= m; i++)
    {
        long long res = cal(i, A[1], B[1], C[1]);
        hp.push(res);
    }
    for (long long i = 2; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            long long res = cal(j, A[i], B[i], C[i]);
            if (res >= hp.top())
                break;
            else
            {
                hp.push(res);
                hp.pop();
            }
        }
    }
    while (hp.size() > 0)
    {
        out.push(hp.top());
        hp.pop();
    }
    while (out.size())
    {
        cout << out.top() << ' ';
        out.pop();
    }
    cout << '\n';
    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// priority_queue<int> q;
// int n, m, a, b, c, ans[100005];
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d%d%d", &a, &b, &c);
//         for (int j = 1; j <= m; j++)
//         {
//             int k;
//             k = a * j * j + b * j + c; // k为函数值y
//             if (i == 1)
//                 q.push(k);
//             else
//             {
//                 if (k < q.top())
//                 {
//                     q.push(k);
//                     q.pop();
//                 }
//                 else
//                     break;
//                 // 如果k已经大于第m小的数了，接下来k仍旧单调递增
//                 // 所以可以直接break掉，一个重要的优化
//             }
//         }
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         ans[i] = q.top();
//         q.pop();
//     } // 记得要逆着输出！
//     for (int i = m; i >= 1; i--)
//         printf("%d ", ans[i]);
//     return 0;
// }
