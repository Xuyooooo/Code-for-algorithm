// https://www.luogu.com.cn/problem/P16426?contestId=274106
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
class ee
{
public:
    int a;
    int loc;
};
bool vis[N];
int c[N];
ee b[N];
int n, t;
long long ans;
bool com(ee b, ee c)
{
    if (b.a < c.a)
        return true;
    if (b.a == c.a && b.loc < c.loc)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].a;
        c[i] = b[i].a;
        b[i].loc = i;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int maxn = max(b[i].a, b[i + 1].a);
        if (maxn < t)
            ans += t - maxn;
    }
    // sort(b + 1, b + n + 1, com);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i & 1)
    //         vis[b[i].loc] = 1;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (vis[b[i].loc] != vis[b[i].loc + 1] && b[i].loc < n)
    //     {
    //         int maxn = max(b[i].a, c[b[i].loc + 1]);
    //         if (maxn < t)
    //             ans += t - maxn;
    //     }
    // }
    cout << ans << '\n';
    return 0;
}