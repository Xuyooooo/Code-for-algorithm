#include <iostream>
using namespace std;
using ll = long long;
#define endl '\n'
ll a, b, p;
long long fastpow(ll a, ll b, ll p)
{
    ll temp = a;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= temp;
            ans %= p;
        }
        temp *= temp;
        temp %= p; // 注意这里应该也得取余一下，不然可能会超
        b >>= 1;
    }
    ans %= p;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=';
    cout << fastpow(a, b, p) << endl;
}