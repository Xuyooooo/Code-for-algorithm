// https://www.luogu.com.cn/problem/P16427?contestId=274106
// https://www.luogu.com.cn/problem/P16427

// 这是作者自己的想法
// 当x!=1时，就要用到操作2，每一次操作二所能增加的数量为(x-1)*x^k，k代表对于这个病毒群来说这是第(k+1)次用操作2
// 那么先进行若干次操作1且保证操作1后数量小于n，然后差的数量检查是否能用操作二补齐
// 作者只考虑了rest是否是(x-1)的倍数情况，但似乎还要考虑rest/(x-1)的值情况
// 只能拿40分
//  #include <iostream>
//  using namespace std;
//  long long n, x;
//  int main()
//  {
//      int t;
//      cin >> t;
//      while (t--)
//      {
//          cin >> n >> x;
//          if (x == 1)
//          {
//              if ((n & (n - 1)) == 0)
//                  cout << "Yes" << '\n';
//              else
//                  cout << "No" << '\n';
//          }
//          else
//          {
//              bool fid = 0;
//              long long now = 1;
//              while (now <= n)
//              {
//                  long long rest = n - now;
//                  if (rest % (x - 1) == 0)
//                  {
//                      if (rest / (x - 1) <= now)
//                      {
//                          fid = 1;
//                          break;
//                      }
//                  }
//                  now *= 2;
//              }
//              if (fid)
//                  cout << "Yes" << '\n';
//              else
//                  cout << "No" << '\n';
//          }
//      }
//      return 0;
//  }

// 这才是正确的思路
// 前面思想一致，只不过每个病毒群的病毒数量为2^k个
// 要实现的是p1*x^k1+p2*x^k2+....=n,是否有解。其中项数目即为2^l(l为操作1的次数)
// 且要满足p1+p2+...为2的幂次方，即∑p=2^l(未合并前)
// 不过要注意的是，项之间可以合并而使系数>=x，那么就不能单纯地对x取模来得到∑p
// 当系数>=x时，原来是：p*x^o，那么就变成了x^(o+p/x)+(p%x)*x^o,系数
// 把其中一个x^w拆成x个x^(w−1)，那么 ∑p ′=∑p+x−1。也就是说 ∑p+m(x−1)=2^l，显然m存在时(2^l−∑p)mod(x−1)=0 且2^l−∑p≥0。

#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, n, x, s;
bool ch()
{
    for (int i = 1; i <= n; i <<= 1)
    {
        if ((i - s) % (x - 1) == 0 && i >= s)
            return 1;
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> x, s = 0;
        if (x == 1)
        {
            if ((1 << __lg(n)) == n)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        int tmp = n;
        while (tmp)
            s += tmp % x, tmp /= x;
        if (ch())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
