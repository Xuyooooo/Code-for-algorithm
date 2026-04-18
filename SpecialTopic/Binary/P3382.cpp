// https://www.luogu.com.cn/problem/P3382
// 模板三分法
// 三分、精度

//==============普通三分================
// 这是作者本人的，但在算多项式结果时有一个测试点会超时
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// double l, r, mid1, mid2;
// const int N = 14;
// const double eps = 1e-6;
// int n;
// double xishu[N];
// using namespace std;
// double calculate(double x)
// {
//     double sum = 0;
//     for (int i = 1; i <= n + 1; i++)
//     {
//         double temp = 1;
//         for (int j = 1; j <= n + 1 - i; j++)
//         {
//             temp *= x;
//         }
//         sum += xishu[i] * temp;
//     }
//     return sum;
// }
// int main()
// {
//     cin >> n >> l >> r;
//     for (int i = 1; i <= n + 1; i++)
//     {
//         cin >> xishu[i];
//     }
//     while (r - l > eps)
//     {
//         mid2 = (l + 2 * r) / 3;
//         mid1 = (r + 2 * l) / 3;
//         if (calculate(mid1) <= calculate(mid2))
//             l = mid1;
//         else
//             r = mid2;
//     }
//     cout << l;
//     return 0;
// }

//====================秦九韶算法三分优化时间复杂度=============
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// double l, r, mid1, mid2;
// const int N = 14;
// const double eps = 1e-6;
// int n;
// double xishu[N];
// using namespace std;
// double calculate(double x) // 秦九韶算法优化
// {
//     double sum = 0;
//     for (int i = n; i >= 0; i--)
//         sum = sum * x + xishu[i];
//     return sum;
// }
// int main()
// {
//     cin >> n >> l >> r;
//     for (int i = n; i >= 0; i--)
//     {
//         cin >> xishu[i];
//     }
//     while (r - l > eps)
//     {
//         mid2 = (l + 2 * r) / 3;
//         mid1 = (r + 2 * l) / 3;
//         if (calculate(mid1) <= calculate(mid2))
//             l = mid1;
//         else
//             r = mid2;
//     }
//     cout << l;
//     return 0;
// }

//===============优选法(华罗庚优选法/黄金分割法)===============
#include <bits/stdc++.h>
#define gold_radio (sqrt(5) - 1) / 2 // 黄金比例Ф≈0.6180339887
#define prec 1e-8                    // 优选法精度
#define MAXN 15                      // 系数最大个数
using namespace std;
int n;
double l, r, a[MAXN], fr, fl; // 注意系数可能为实数
bool getr = true, getl = true;
double f(double x)
{ // 此函数计算线性方程f(x)
    double ans = 0, k = 1;
    for (int i = n; i >= 0; i--)
    {
        ans += k * a[i];
        k *= x;
    }
    return ans;
}
int main()
{
    cin >> n;
    cin >> l >> r;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    while (r - l > prec)
    {                                           // 优选法，其实也只是三分的优化
        double midr = (r - l) * gold_radio + l; // 根据黄金比例分割中间两个点
        double midl = (r - l) * (1 - gold_radio) + l;
        if (getl)
            fl = f(midl); // 精妙之处
        if (getr)
            fr = f(midr);
        if (fl > fr)
        {
            r = midr, fr = fl, getl = true, getr = false;
            continue;
        }
        if (fl < fr)
        {
            l = midl, fl = fr, getl = false, getr = true;
            continue;
        }
        if (fl == fr)
            r = midr, l = midl, getl = true, getr = true; // 虽然没考虑精度，但只做提醒。此处一般人不写，注意l ≈r时已经得出答案，所以肯定是在异侧，可以同时向上
    }
    cout << fixed << setprecision(5) << r << endl; // 注意题目要求精度
    return 0;
}
