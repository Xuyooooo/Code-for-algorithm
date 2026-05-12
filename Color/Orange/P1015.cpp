// // https://www.luogu.com.cn/problem/P1015

// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;
// int n;
// string add(string a, string b)
// {
//     string res;
//     int p = a.size();
//     int carry = 0;
//     for (int i = p - 1; i >= 0; i--)
//     {
//         res = char((a[i] + b[i] - 96 + carry) % n + '0') + res;
//         carry = (a[i] + b[i] + carry - 96) / n;
//     }
//     if (carry)
//         res = char(carry + '0') + res;
//     return res;
// }
// string add1(string a, string b)
// {
//     string res;
//     int p = a.size();
//     int carry = 0;
//     for (int i = p - 1; i >= 0; i--)
//     {
//         res = char((a[i] + b[i] - 96 + carry) % n + '0') + res;
//         carry = (a[i] + b[i] + carry - 96) / n;
//     }
//     if (carry)
//         res = char(carry + '0') + res;
//     return res;
// }
// // class dd
// // {
// // public:
// //     dd();
// //     dd(int newa, int newb, int newc);

// // private:
// //     int a, b, c;
// // };
// // dd::dd(int newa, int newb, int newc) : a(newa), b(newb), c(newc)
// // {
// // }
// // dd::dd() : a(1), b(2), c(3)
// // {
// // }
// // dd da(0, 0, 0); // 自动调用构造函数
// // // 没写构造函数的话，系统会自动生成一个构造函数，只不过啥都不干(写了构造函数的话，不会生成)
// // dd db; // 调用不带参数的构造函数(若不存在会报错)
// // // 构造函数也可以函数重载
// bool check(string a)
// {
//     for (int i = 0, j = a.size() - 1; i <= j; i++, j--)
//     {
//         if (a[i] != a[j])
//             return false;
//     }
//     return true;
// }
// int main()
// {
//     cin >> n;
//     string input;
//     cin >> input;
//     int k = 1;
//     if (n != 16)
//     {
//         while (k <= 30)
//         {
//             string input1 = input;
//             reverse(input.begin(), input.end());
//             input = add(input1, input);
//             if (check(input))
//                 break;
//             k++;
//         }
//         if (k == 31)
//             cout << "Impossible!" << '\n';
//         else
//             cout << "STEP=" << k << '\n';
//     }
//     else
//     {
//         while (k <= 30)
//         {
//             string input1 = input;
//             reverse(input.begin(), input.end());
//             input = add1(input1, input);
//             if (check(input))
//                 break;
//             k++;
//         }
//         if (k == 31)
//             cout << "Impossible!" << '\n';
//         else
//             cout << "STEP=" << k << '\n';
//     }
//     return 0;
// }
// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int N;
// int charToNum(char c)
// {
//     if (c >= '0' && c <= '9')
//         return c - '0';
//     if (c >= 'A' && c <= 'Z')
//         return c - 'A' + 10;
//     if (c >= 'a' && c <= 'z')
//         return c - 'a' + 10;
//     return 0;
// }
// char numToChar(int n)
// {
//     if (n >= 0 && n <= 9)
//         return n + '0';
//     return n - 10 + 'A';
// }
// string add(string a, string b)
// {
//     string res;
//     int carry = 0;
//     int i = a.size() - 1;
//     int j = b.size() - 1;
//     while (i >= 0 || j >= 0 || carry)
//     {
//         int x = (i >= 0) ? charToNum(a[i]) : 0;
//         int y = (j >= 0) ? charToNum(b[j]) : 0;
//         int sum = x + y + carry;
//         res += numToChar(sum % N);
//         carry = sum / N;
//         i--;
//         j--;
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }
// bool check(string s)
// {
//     string t = s;
//     reverse(t.begin(), t.end());
//     return s == t;
// }
// int main()
// {
//     string M;
//     cin >> N >> M;
//     if (check(M))
//     {
//         cout << "STEP=0" << endl;
//         return 0;
//     }
//     for (int k = 1; k <= 30; k++)
//     {
//         string revM = M;
//         reverse(revM.begin(), revM.end());
//         M = add(M, revM);
//         if (check(M))
//         {
//             cout << "STEP=" << k << endl;
//             return 0;
//         }
//     }
//     cout << "Impossible!" << endl;
//     return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

const int LEN = 500;

// 判断回文
bool is_pala(const vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            return false;
    }
    return true;
}

// 进制加法：m = m + reverse(m)
vector<int> add_reverse(vector<int> a, int base)
{
    vector<int> b = a;
    reverse(b.begin(), b.end());

    vector<int> res;
    int carry = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum = a[i] + b[i] + carry;
        res.push_back(sum % base);
        carry = sum / base;
    }
    if (carry)
        res.push_back(carry);
    return res;
}

int main()
{
    int n;
    string s;
    if (!(cin >> n >> s))
        return 0;

    vector<int> m;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
            m.push_back(s[i] - '0');
        else
            m.push_back(toupper(s[i]) - 'A' + 10);
    }

    for (int step = 0; step <= 30; step++)
    {
        if (is_pala(m))
        {
            cout << "STEP=" << step << endl;
            return 0;
        }
        m = add_reverse(m, n);
    }

    cout << "Impossible!" << endl;
    return 0;
}