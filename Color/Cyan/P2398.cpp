// 由欧拉函数性质即：x = 累加( oula(d) )其中d | x。即任意正整数x等于他所有的约数d的欧拉函数之和
// 即gcd(i,j) = d | gcd(i,j)累加。又i,j的所有公约数都是最大公约数的因子。
// 则d | gcd(i,j) 等价于d同时整除i和j
// d的枚举提到外面，且取值范围是1~n
// 当d确定时，oula[d]为常数，则只用看有多少对(i,j)满足i和j都是d的倍数
// 则有 (n/d)*(n/d)对

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 1e5 + 1;
ll oula[N], n;

void init(vector<int> &primes, vector<bool> &is_prime)
{
    oula[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            oula[i] = i - 1;
        }
        for (auto &p : primes)
        {
            if (i * p > n)
                break;
            is_prime[i * p] = 0;
            if (i % p == 0)
            {
                oula[i * p] = oula[i] * p;
                break;
            }
            else
            {
                oula[i * p] = oula[i] * oula[p];
            }
        }
    }
}
void solve()
{
    ll ans = 0;
    cin >> n;
    vector<int> primes;
    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    init(primes, is_prime);
    for (int i = 1; i <= n; i++)
    {
        ans += oula[i] * (n / i) * (n / i);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}