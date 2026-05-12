// https://www.luogu.com.cn/problem/P16437

#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int ans, n, m, v, k, b;
int main()
{
    cin >> n >> m >> k;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        a[b]++;
    }
    cin >> v;
    for (int i = 1; i <= k; i++)
    {
        cin >> b;
        if (b != v && a[b] > 0)
        {
            ans -= a[b];
            a[b] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}