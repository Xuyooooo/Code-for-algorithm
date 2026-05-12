// https://www.luogu.com.cn/problem/P1866

#include <iostream>
#include <algorithm>

using namespace std;

const int modd = 1e9 + 7;

const int N = 51;
int a[N], n, maxn;
unsigned long long ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    sort(a + 1, a + n + 1);
    if (maxn < n)
    {
        cout << 0 << '\n';
        return 0;
    }
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= a[i] - (i - 1);
    }
    if (ans > 0)
        cout << ans << '\n';
    else
        cout << 0 << '\n';
    return 0;
}