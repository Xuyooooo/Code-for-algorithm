// https://www.luogu.com.cn/problem/P16425?contestId=274106
#include <iostream>
using namespace std;
long long n, m, d;
int main()
{
    long long ans = 0;
    cin >> n >> m >> d;
    long long sum = n * d + n;
    if (sum == m)
        cout << ans << '\n';
    else if (sum < m)
    {
        long long rest = m - sum;
        if (rest <= n)
            ans += rest;
        else
        {
            ans += n;
            ans += (rest - n) / (d + 1);
        }
        cout << ans << '\n';
    }
    else if (sum > m)
        cout << -1 << '\n';
    return 0;
}