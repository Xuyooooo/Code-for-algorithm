#include <iostream>
using namespace std;
string a[5010];
// 第一种递归
//  int num(int n)
//  {
//      if (n == 1)
//          return a[1];
//      if (n == 2)
//          return a[2];
//      a[n] = num(n - 1) + num(n - 2);
//      return a[n];
//  }
//  int main()
//  {
//      ios::sync_with_stdio(0);
//      cin.tie(0);
//      a[1] = 1;
//      a[2] = 2;
//      int N;
//      cin >> N;
//      cout << num(N);
//  }
// 第二种，直接操作
//  int main()
//  {
//      int N;
//      cin >> N;
//      a[1] = 1;
//      a[2] = 2;
//      for (int i = 3; i <= N; i++)
//      {
//          a[i] = a[i - 1] + a[i - 2];
//      }
//      cout << a[N];
//  }
// 第三种，数据范围过大
string simulate(string a, string b)
{
    string c;
    int p1 = a.size() - 1, p2 = b.size() - 1;
    char carry = '0';
    while (p1 >= 0 && p2 >= 0)
    {
        if (a[p1] + b[p2] + carry - 144 >= 10)
        {
            c.insert(0, 1, a[p1] + b[p2] + carry - 96 - 10);
            carry = '0' + (a[p1] + b[p2] + carry - 144) / 10;
        }
        else
        {
            c.insert(0, 1, a[p1] + b[p2] + carry - 96);
            carry = '0';
        }
        p1--, p2--;
    }
    while (p1 >= 0)
    {
        if (a[p1] + carry - 96 >= 10)
        {
            c.insert(0, 1, a[p1] + carry - 48 - 10);
            carry = '0' + (a[p1] + carry - 96) / 10;
        }
        else
        {
            c.insert(0, 1, a[p1] + carry - 48);
            carry = '0';
        }

        p1--;
    }
    while (p2 >= 0)
    {
        if (b[p2] + carry - 96 >= 10)
        {
            c.insert(0, 1, b[p2] + carry - 48 - 10);
            carry = '0' + (b[p2] + carry - 96) / 10;
        }
        else
        {
            c.insert(0, 1, b[p2] + carry - 48);
            carry = '0';
        }

        p2--;
    }
    if (carry != '0')
        c.insert(0, 1, carry);
    return c;
}
int main()
{
    int N;
    cin >> N;
    a[1] = "1";
    a[2] = "2";
    for (int i = 3; i <= N; i++)
    {
        a[i] = simulate(a[i - 1], a[i - 2]);
    }
    cout << a[N];
}