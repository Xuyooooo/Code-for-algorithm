#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int a[N], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (a[i] == a[n - i + 1])
            a[i] = a[n - i + 1] = 1;
        else
            a[i] = a[n - i + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}