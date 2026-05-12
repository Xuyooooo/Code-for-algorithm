// https://www.luogu.com.cn/problem/P1138

//==========作者思路==========
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 5;
// int a[N], n, k;
// int main()
// {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     sort(a + 1, a + n + 1);
//     int j = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         if (a[i] != a[i - 1])
//             j++;
//         if (j == k)
//         {
//             cout << a[i] << '\n';
//             break;
//         }
//     }
//     if (j != k)
//         cout << "NO RESULT" << '\n';
//     return 0;
// }

//===============桶排序=================
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, k, a[100005], t = 0, to[30005]; // to为桶，t为统计桶中出现过的数是第几小
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         to[a[i]] = 1; // a[i]出现过，放进桶里
//     }
//     for (int i = 1; i <= 30005; i++)
//     {
//         if (to[i] == 1)
//             ++t; // 只要这个数是有值的，那么这个数就是第t小整数
//         if (t == k)
//         { // 如果t==k，就代表这个数是第k小，直接输出i，就可结束程序
//             cout << i;
//             return 0;
//         }
//     }
//     cout << "NO RESULT";
//     return 0;
// }

//==================set法=================
#include <bits/stdc++.h>
using namespace std;
int n, k;
set<int> Set; // set会自动去重，且默认升序排列
int main()
{
    cin >> n >> k;
    for (int i = 1, num; i <= n; i++)
    {
        cin >> num;
        Set.insert(num); // 读入，插入
    }
    if (Set.size() < k) // 无解
        cout << "NO RESULT";
    else
    {
        auto it = Set.begin(); // 容器头迭代器
        advance(it, k - 1);    // 迭代器前进函数，注意是k-1(让迭代器向后移动n个位置,n>0向后，n<0向前)
        cout << *it;           // 输出迭代器所指向的值
    }
    return 0;
}
