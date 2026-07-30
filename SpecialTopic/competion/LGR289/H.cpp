#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, q, h, w, opt, t;
int a[51][51];
bool b[10000] = {0};
int main()
{
    int num1 = 0, num2 = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int id = 1;
    cin >> n >> m >> q;
    for (int k = 1; k <= q; k++)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> h >> w;
            if (x + h - 1 > n || y + w - 1 > m || x > n || y > m)
            {
                cout << "Error" << '\n';
            }
            else
            {
                bool ok = 1;
                for (int i = x; i <= x + h - 1; i++)
                {
                    for (int j = y; j <= y + w - 1; j++)
                    {
                        if (a[i][j] && b[a[i][j]])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (!ok)
                    {
                        break;
                    }
                }
                if (ok)
                {
                    cout << id << '\n';
                    for (int i = x; i <= x + h - 1; i++)
                    {
                        for (int j = y; j <= y + w - 1; j++)
                        {
                            a[i][j] = id;
                        }
                    }
                    b[id] = 1;
                    id++;
                }
                else
                {
                    cout << "Error" << '\n';
                }
            }
        }
        else if (opt == 2)
        {
            cin >> t;
            if (!b[t])
                cout << "Error" << '\n';
            else
            {
                cout << "Remove" << '\n';
                b[t] = 0;
            }
        }
        else
        {
            cin >> x >> y;
            if (a[x][y] && b[a[x][y]])
                cout << a[x][y] << '\n';
            else
                cout << 0 << '\n';
        }
    }
    for (int i = 1; i < id; i++)
    {
        if (b[i])
            num1++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] && b[a[i][j]])
                num2++;
        }
    }
    cout << num1 << ' ' << num2 << '\n';
    return 0;
}