// https://www.luogu.com.cn/problem/P2437
// 2437 蜜蜂路线
// 高精度、递推

#include <iostream>
#include <string>
const int N = 1010;
using namespace std;
string line[N];
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
    line[1] = line[2] = "1";
    for (int i = 3; i <= 1000; i++)
    {
        line[i] = simulate(line[i - 1], line[i - 2]);
    }
    int n, m;
    cin >> m >> n;
    cout << line[n - m + 1] << endl;
    return 0;
}