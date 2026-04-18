

#include <bits/stdc++.h>
using namespace std;
int a, b, m, c, d, k;
int main()
{
    cin >> a >> b >> m >> c >> d >> k;
    for (int i = k; i <= m; i += k)
    {
        int y = (b + i) % 60;
        int x = a + (b + i) / 60;
        if (c < a || (c == a && d <= b))
        {
            x -= 24;
            if ((x == c && y > d) || x > c)
            {
                x = x + 24 - 1;
                x %= 24;
            }
            else
            {
                x += 24;
                x %= 24;
            }
        }
        else
        {

            if ((x == c && y > d) || x > c)
            {
                x %= 24;
                x -= 1;
            }
            if (x < 0)
                x += 24;
        }

        cout << x << ' ' << y << '\n';
    }
    return 0;
}