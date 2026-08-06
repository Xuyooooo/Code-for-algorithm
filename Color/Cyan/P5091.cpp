#include <iostream>
#include <string>

using namespace std;
using ll = long long;

// 得到m的欧拉函数的函数
ll get_phi(ll m)
{
    ll res = m;
    for (ll i = 2; i * i <= m; i++)
    {
        if (m % i == 0) // 只要能够整除就说明该数为质数(因为后续会将所有的为质数的整数倍的合数所去掉)
        {
            res = res / i * (i - 1); // 将分数乘法转换为整数乘除
            while (m % i == 0)
                m /= i;
        }
    }
    if (m > 1) // 检查是否有大于根号m的质因子
        res = res / m * (m - 1);
    return res;
}

ll qpow(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, m;
    if (!(cin >> a >> m))
        return 0;

    ll phi = get_phi(m);
    ll b = 0;
    bool flag = false;
    char ch;
    while (cin >> ch && !isdigit(ch))
        ; // 跳过空格和换行

    while (isdigit(ch))
    {
        b = b * 10 + (ch - '0');
        if (b >= phi) // 欧拉降幂定理条件分支的判断
        {
            flag = true;
            b %= phi;
        }
        if (!(cin >> ch))
            break;
    }
    if (flag)
    {
        b += phi;
    }
    cout << qpow(a, b, m) << "\n";

    return 0;
}