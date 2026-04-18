// 这种方法可以继续优化，根本不需sort，在输入的过程中找到最大高度，再直接便利即可
//  #include <iostream>
//  #include <algorithm>
//  using namespace std;
//  const int N = 1e6 + 10;
//  int wood_height[N];
//  int main()
//  {
//      int n, m, fell_height, sum;
//      cin >> n >> m;
//      for (int i = 1; i <= n; i++)
//      {
//          cin >> wood_height[i];
//      }
//      sort(wood_height + 1, wood_height + n + 1);
//      int start = wood_height[0], end = wood_height[n], mid;
//      while (1)
//      {
//          mid = start + ((end - start) >> 1);
//          sum = 0;
//          for (int i = 0; i <= n; i++)
//          {
//              if (wood_height[i] > mid)
//                  sum += wood_height[i] - mid;
//          }
//          if (sum == m)
//          {
//              fell_height = wood_height[mid];
//              break;
//          }
//          else if (sum < m)
//              end = mid;
//          else
//              start = mid;
//      }
//      fell_height = mid;
//      cout << fell_height;
//      return 0;
//  }
// 二分的正确做法
// 不需要排序，直接遍历且一旦sum>=m就结束
// 直到l=r，此时就一定是ans
#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int a[N], mid, l, r, n, m;

bool check(int x)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
            s += a[i] - x;
        if (s >= m)
            return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    l = 0, r = 1e9;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
// 还可以这样子做
// 假设已砍过了i棵树（树由高到低排），那此时被砍过的i棵树的高度均等于第i+1棵树的高度
// 再砍一棵树（砍第i+1棵）后获得的新高度为（第i+1棵树的高度-第i+2棵树的高度）*（i+1）。
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// int tree[1000001];
// int n, m;
// int main()
// {
//     int i, num, ans;
//     long long sum;
//     scanf("%d%d", &n, &m);
//     for (i = 1; i <= n; i++)
//         scanf("%d", &tree[i]);
//     sort(tree + 1, tree + n + 1);
//     sum = 0;
//     num = n;
//     while (sum < m)
//     {
//         sum += (tree[num] - tree[num - 1]) * (n - num + 1);
//         num--;
//     }
//     //此时sum大于了m，则再找到恰好高度，多的高度均分给已经砍过的每棵树再加tree[num-1]即可
//     num++;
//     ans = tree[num - 1] + (sum - m) / (n - num + 1);
//     printf("%d\n", ans);
//     return 0;
// }
// 对任意一个正整数，都可以拆分成多个2^n之和（每个只用一次，相当于二进制转换）
#include <bits/stdc++.h>
using namespace std;
long long a[1000006];
long long n, m;
bool check(int mid)
{
    long long ans = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
            ans += (a[i] - mid); // 常规判断，注意树一定先要高于mid
    }
    return ans < m; // 不能取等，因为等于也满足条件，不用退回
}
int main()
{
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long mid = 0; // 答案指针
    for (long long i = 20; i >= 0; i--)
    {                  // 由大到小保证凑出答案（答案范围设为2^20 ~ 0）
        mid += 1 << i; // 2^i
        if (check(mid))
            mid -= 1 << i; // 发现木头不足要退回
    }
    cout << mid << endl;
    return 0;
}
