// https://www.luogu.com.cn/problem/P1318

// 单调栈，模拟
//  这是初始代码，想的片面了，这种代码AC时要求右边存在高的柱子挡住水不流出
//   #include <iostream>
//   #include <algorithm>
//   using namespace std;
//   const int N = 1e5 + 10;
//   int num[N], height[N];
//   int n;
//   int main()
//   {
//      ios::sync_with_stdio(0);
//      cin.tie(0);
//      int size = 2, temp, sum = 0;
//      cin >> n;
//      for (int i = 1; i <= n; i++)
//          num[i] = 1;
//      cin >> temp;
//      height[1] = temp;
//      for (int i = 2; i <= n; i++)
//      {
//          cin >> temp;
//          if (temp == height[size - 1])
//              num[size - 1]++;
//          else
//              height[size++] = temp;
//      }
//      int i = 3, now = 2;
//      while (i <= size - 2)
//      {
//          if (height[now] > height[i])
//          {
//              sum += (height[now] - height[i]) * num[i];
//          }
//          else
//              now = i;
//          i++;
//      }
//      cout << sum << '\n';
//      return 0;
//  }

//=============在第一个思路上优化
// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 1e4 + 10; // 题目N最大10000
// int height[N];
// int n;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     int max_h = 0, max_pos = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> height[i];
//         if (height[i] > max_h)
//         {
//             max_h = height[i];
//             max_pos = i; // 记录最高柱子的位置
//         }
//     }
//     int sum = 0;
//     // 左半部分：从左往右扫到最高点
//     int left_now = height[1];
//     for (int i = 2; i < max_pos; i++)
//     {
//         if (height[i] < left_now)
//         {
//             sum += (left_now - height[i]);
//         }
//         else
//         {
//             left_now = height[i];
//         }
//     }
//     // 右半部分：从右往左扫到最高点
//     int right_now = height[n];
//     for (int i = n - 1; i > max_pos; i--)
//     {
//         if (height[i] < right_now)
//         {
//             sum += (right_now - height[i]);
//         }
//         else
//         {
//             right_now = height[i];
//         }
//     }

//     cout << sum << '\n';
//     return 0;
// }

//============这是最经典解法--记录每个位置的左右最高峰========
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// const int N = 10005;
// int h[N], L[N], R[N];

// int main()
// {
//     int n;
//     if (!(cin >> n))
//         return 0;

//     for (int i = 1; i <= n; i++)
//         cin >> h[i];
//     // 1. 预处理每个位置左边的最高柱子
//     for (int i = 1; i <= n; i++)
//         L[i] = max(L[i - 1], h[i]);
//     // 2. 预处理每个位置右边的最高柱子
//     for (int i = n; i >= 1; i--)
//         R[i] = max(R[i + 1], h[i]);
//     // 3. 累加每个位置的储水量
//     long long sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int water = min(L[i], R[i]) - h[i];
//         if (water > 0)
//             sum += water;
//     }
//     cout << sum << endl;
//     return 0;
// }

//================优雅单调栈=============
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 10005;
int h[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    stack<int> st; // 存储下标
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // 当栈不为空，且当前高度大于栈顶高度，说明形成了“凹槽”
        while (!st.empty() && h[i] > h[st.top()])
        {
            int mid = st.top(); // 凹槽的底部
            st.pop();
            if (st.empty())
                break;           // 没有左边界，存不住水
            int left = st.top(); // 左边界的下标
            int right = i;       // 右边界的下标

            // 计算横向积水
            int height = min(h[left], h[right]) - h[mid]; // 水的高度（木桶效应：取短板）
            int width = right - left - 1;                 // 水的宽度
            sum += (long long)height * width;
        }
        st.push(i); // 当前柱子入栈
    }
    cout << sum << endl;
    return 0;
}