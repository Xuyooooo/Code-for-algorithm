#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
ll a, b, m;
ll cal(ll x)
{
    if (x < 2)
        return 0;
    vector<bool> isPrime(x + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= x; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
        for (int p : primes)
        {
            if (i * p > x)
                break;
            isPrime[i * p] = false;
            if (i % p == 0)
                break;
        }
    }
    return primes.size();
}
ll quickPow(ll b)
{
    ll ans = 1, temp = a;
    while (b)
    {
        if (b & 1)
        {
            ans *= temp;
            ans %= m;
        }
        temp *= temp;
        temp %= m;
        b >>= 1;
    }
    ans %= m;
    return ans;
}
int main()
{
    cin >> a >> b >> m;
    ll save = cal(m);
    if (__gcd(a, save) == 1)
    {
        cout << 1 % m << '\n';
    }
    else
    {
        
    }
    cout << quickPow(cal(m)) << '\n';
    return 0;
}