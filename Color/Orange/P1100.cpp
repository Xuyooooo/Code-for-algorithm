// https://www.luogu.com.cn/problem/P1100

// 字符串，模拟
#include <iostream>
#include <string>

using namespace std;

string a;
string b;
unsigned long long n, ans;

unsigned long long quick_mi(int n)
{
    unsigned res = 1, temp = 2;
    while (n)
    {
        if (n & 1)
            res *= temp;
        temp *= temp;
        n /= 2;
    }
    return res;
}
void transform()
{
    while (n)
    {
        a = char(n % 2 + '0') + a;
        n /= 2;
    }
    while (a.size() < 32)
    {
        a = '0' + a;
    }
    for (int i = 16; i <= 31; i++)
    {
        b = b + a[i];
    }
    for (int i = 0; i <= 15; i++)
    {
        b = b + a[i];
    }
}
int main()
{
    cin >> n;
    transform();
    for (int i = 31; i >= 0; i--)
    {
        if (b[i] == '1')
            ans += quick_mi(31 - i);
    }
    cout << ans << '\n';
    return 0;
}