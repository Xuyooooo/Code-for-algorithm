// https://www.luogu.com.cn/problem/P1010

//==========作者本人想的递归，也是过了=============
// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;
// int n, mi;
// void output(int x)
// {
//     if (x == 0)
//     {
//         cout << 0;
//         return;
//     }
//     if (x == 1)
//     {
//         return;
//     }
//     if (x == 2)
//     {
//         cout << 2;
//         return;
//     }
//     vector<int> save(100);
//     int k = 1;
//     for (int i = __lg(x); i >= 0; i--)
//     {
//         if ((x >> i) & 1)
//         {
//             save[k++] = i;
//         }
//     }
//     for (int i = 1; i < k - 1; i++)
//     {
//         if (save[i] != 1)
//         {
//             cout << "2(";
//             output(save[i]);
//             cout << ")+";
//         }
//         else
//         {
//             cout << "2+";
//         }
//     }
//     if (save[k - 1] != 1)
//     {
//         cout << "2(";
//         output(save[k - 1]);
//         cout << ')';
//     }
//     else
//     {
//         cout << "2";
//     }
// }
// int main()
// {
//     cin >> n;
//     if (n == 1)
//     {
//         cout << "2(0)" << '\n';
//         return 0;
//     }
//     if (n == 2)
//     {
//         cout << "2" << '\n';
//         return 0;
//     }
//     output(n);
//     return 0;
// }

//==============豆包给的思路(和作者本人的基本一致)==================
#include "bits/stdc++.h"
#define int long long
using namespace std;
int a[200] = {1};
void find(int n)
{
    if (n == 1)
    {
        cout << "2(0)";
        return;
    }
    if (n == 2)
    {
        cout << "2";
        return;
    }
    int i;
    for (i = 0; i < 200; i++)
        if (a[i] <= n && a[i + 1] > n)
            break;
    cout << "2";
    if (i != 1)
    {
        cout << "(";
        find(i);
        cout << ")";
    }
    if (n > a[i])
    {
        cout << "+";
        find(n - a[i]);
    }
}
signed main()
{
    for (int i = 1; i < 200; i++)
        a[i] = a[i - 1] * 2;
    int n;
    cin >> n;
    find(n);
    return 0;
}