#include <iostream>
using namespace std;
int main()
{
    int a, b, c, m, p, q, t;
    int ans = 1e9;
    cin >> a >> b >> c >> m >> p >> q >> t;
    int ok = 0;
    if (a + b + m < t)
    {
        ok = 1;
        ans = min(ans, p);
    }
    if (a + c + m < t)
    {
        if (ans > q)
        {
            ans = q;
            ok = 2;
        }
    }
    if (ok)
    {
        cout << "YES" << '\n';
        if (ok == 1)
        {
            cout << ans << '\n';
            cout << "bus" << '\n';
        }
        else
        {
            cout << ans << '\n';
            cout << "taxi" << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}