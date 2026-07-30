#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int d[N];
int n, m, c, s;
int main()
{
    int num1 = 0, num2 = 0;
    map<int, int> a;
    map<int, int> b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> s;
        a[c] = 1;
        b[c] = s;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!a[d[i]])
            num1++;
        else if (b[d[i]] < 60)
            num2++;
    }
    cout << num1 << ' ' << num2 << '\n';
    return 0;
}