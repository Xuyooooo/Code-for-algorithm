#include <iostream>
using namespace std;
long long n, x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> n >> x >> y;
        if (n == 1)
        {
            if (x == y)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            if (y >= 0)
            {
                if (n * y <= x)
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
            }
            else
            {
                if (x >= 0)
                    cout << "YES" << '\n';
                else
                {
                    if (y <= n * x)
                        cout << "YES" << '\n';
                    else
                        cout << "NO" << '\n';
                }
            }
        }
    }
    return 0;
}