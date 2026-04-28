// https://www.luogu.com.cn/problem/P1015

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string add(string a, string b)
{
    string res;
    int p = a.size();
    int carry;
    for (int i = p - 1; i >= 0; i--)
    {
        res = char((a[i] + b[i] - 96 + carry) % n + '0') + res;
        carry = (a[i] + b[i] + carry - 96) / n;
    }
    if (carry)
        res = char(carry + '0') + res;
    return res;
}
// class dd
// {
// public:
//     dd();
//     dd(int newa, int newb, int newc);

// private:
//     int a, b, c;
// };
// dd::dd(int newa, int newb, int newc) : a(newa), b(newb), c(newc)
// {
// }
// dd::dd() : a(1), b(2), c(3)
// {
// }
// dd da(0, 0, 0); // 自动调用构造函数
// // 没写构造函数的话，系统会自动生成一个构造函数，只不过啥都不干(写了构造函数的话，不会生成)
// dd db; // 调用不带参数的构造函数(若不存在会报错)
// // 构造函数也可以函数重载
bool check(string a)
{
    for (int i = 0, j = a.size() - 1; i <= j; i++, j--)
    {
        if (a[i] != a[j])
            return false;
    }
    return true;
}
int main()
{

    cin >> n;
    string input;
    cin >> input;
    int k = 1;
    while (k <= 30)
    {
        string input1 = input;
        reverse(input.begin(), input.end());
        input = add(input1, input);
        if (check(input))
            break;
        k++;
    }
    if (k == 31)
        cout << "Impossible!" << '\n';
    else
        cout << "STEP=" << k << '\n';
    return 0;
}