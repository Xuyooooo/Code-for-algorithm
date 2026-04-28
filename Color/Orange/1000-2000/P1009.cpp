// https://www.luogu.com.cn/problem/P1009
// 高精度、模拟

#include <iostream>
#include <string>
using namespace std;
const int N = 51;
string jiecheng[N];
int n;
string add(string a, string b)
{
    int p1 = a.size(), p2 = b.size();
    int size = max(a.size(), b.size());
    if (p1 > p2)
    {
        for (int i = 1; i <= p1 - p2; i++)
            b = '0' + b;
    }
    else if (p1 < p2)
    {
        for (int i = 1; i <= p2 - p1; i++)
            a = '0' + a;
    }
    string res;
    int carry = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        res = char((a[i] - '0' + b[i] - '0' + carry) % 10 + '0') + res;
        carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
    }
    if (carry)
        res = char('0' + carry) + res;
    return res;
}
string multipfy(string a, int y)
{
    string b = to_string(y);
    int size = b.size();
    if (size == 2)
    {
        int i = 1;
        string temp1;
        int carry = 0;
        for (int j = a.size() - 1; j >= 0; j--)
        {
            temp1 = char(((a[j] - '0') * (b[i] - '0') + carry) % 10 + '0') + temp1;
            carry = ((a[j] - '0') * (b[i] - '0') + carry) / 10;
        }
        if (carry)
            temp1 = char(carry + '0') + temp1;
        i = 0;
        string temp2;
        carry = 0;
        for (int j = a.size() - 1; j >= 0; j--)
        {
            temp2 = char(((a[j] - '0') * (b[i] - '0') + carry) % 10 + '0') + temp2;
            carry = ((a[j] - '0') * (b[i] - '0') + carry) / 10;
        }
        if (carry)
            temp2 = char(carry + '0') + temp2;
        temp2 = temp2 + '0';
        string ans = add(temp1, temp2);
        return ans;
    }
    else
    {
        int i = 0;
        string temp2;
        int carry = 0;
        for (int j = a.size() - 1; j >= 0; j--)
        {
            temp2 = char(((a[j] - '0') * (b[i] - '0') + carry) % 10 + '0') + temp2;
            carry = ((a[j] - '0') * (b[i] - '0') + carry) / 10;
        }
        if (carry)
            temp2 = char(carry + '0') + temp2;
        return temp2;
    }
}
string cal_jiecheng(int n)
{
    if (!jiecheng[n].empty())
        return jiecheng[n];
    else
        jiecheng[n] = multipfy(cal_jiecheng(n - 1), n);
    return jiecheng[n];
}
string sum_add(int n)
{
    int size = jiecheng[n].size();
    for (int i = 1; i <= n - 1; i++)
    {
        int cnt = size - jiecheng[i].size();
        for (int j = 1; j <= cnt; j++)
            jiecheng[i] = '0' + jiecheng[i];
    }
    string res;
    int carry = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        int add = carry;
        for (int j = 1; j <= n; j++)
        {
            add += jiecheng[j][i] - '0';
        }
        res = (char)(add % 10 + '0') + res;
        carry = add / 10;
    }
    if (carry)
        res = char(carry + '0') + res;
    return res;
}
int main()
{
    jiecheng[1] = "1";
    jiecheng[2] = "2";
    jiecheng[3] = "6";
    jiecheng[4] = "24";
    jiecheng[5] = "120";
    cin >> n;
    cal_jiecheng(n);
    cout << sum_add(n) << '\n';
    return 0;
}