// https://www.luogu.com.cn/problem/P1601
#include <iostream>
#include <string>
using namespace std;
string simulate(string a, string b)
{
   string c;
   int p1 = a.size() - 1, p2 = b.size() - 1;
   char carry = '0';
   while (p1 >= 0 && p2 >= 0) // 其实不用分if-else，用取余式子可以合并
   {
      if (a[p1] + b[p2] + carry - 144 >= 10)
      {
         c.insert(0, 1, a[p1] + b[p2] + carry - 96 - 10); // 可以不用insert，直接用a=c+a
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
   string a, b;
   cin >> a;
   cin >> b;
   string c = simulate(a, b);
   cout << c;
}

// 下面是N进制的高精度加法模板
//  #include <iostream>
//  #include <string>
//  #include <vector>
//  #include <algorithm>

// using namespace std;

// // 1. 将字符转为数值 (兼容 0-9, A-F)
// int getVal(char c)
// {
//    if (isdigit(c))
//       return c - '0';
//    if (isupper(c))
//       return c - 'A' + 10;
//    if (islower(c))
//       return c - 'a' + 10;
//    return 0;
// }

// // 2. 将数值转为字符 (用于输出)
// char getChar(int v)
// {
//    if (v <= 9)
//       return v + '0';
//    return v - 10 + 'A';
// }

// string addN(string s1, string s2, int N)
// {
//    vector<int> A, B, C;
//    // 倒序存储
//    for (int i = s1.size() - 1; i >= 0; i--)
//       A.push_back(getVal(s1[i]));
//    for (int i = s2.size() - 1; i >= 0; i--)
//       B.push_back(getVal(s2[i]));

//    int carry = 0;
//    for (int i = 0; i < A.size() || i < B.size(); i++)
//    {
//       int sum = carry;
//       if (i < A.size())
//          sum += A[i];
//       if (i < B.size())
//          sum += B[i];

//       C.push_back(sum % N); // 关键：对 N 取模
//       carry = sum / N;      // 关键：逢 N 进一
//    }

//    if (carry)
//       C.push_back(carry);

//    // 转回字符串并翻转
//    string res = "";
//    for (int i = 0; i < C.size(); i++)
//       res += getChar(C[i]);
//    reverse(res.begin(), res.end());

//    return res;
// }

// int main()
// {
//    int n;
//    string a, b;
//    while (cin >> n >> a >> b)
//    {
//       cout << addN(a, b, n) << endl;
//    }
//    return 0;
// }