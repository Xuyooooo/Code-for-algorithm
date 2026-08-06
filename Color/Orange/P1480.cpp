// https://www.luogu.com.cn/problem/P1480
// 高精度除法;大数/long long
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

vector<int> div(const vector<int> &a, ll &b, ll &r)
{
    vector<int> res;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0)
    {
        res.pop_back();
    }
    return res;
}
void solve()
{
    string a;
    ll b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    ll r = 0;
    vector<int> res = div(A, b, r);
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    return;
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