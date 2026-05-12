#include <iostream>
using namespace std;
const int N = 2e5 + 3;
int a[N];
int n, m, c, k;
int main()
{
    cin >> n >> m >> c >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k < 3 * c)
    {
        cout << -1 << '\n';
        return 0;
    }
    else
    {
        bool ok = 0;
    }
}