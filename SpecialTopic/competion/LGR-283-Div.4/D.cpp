

#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N], n, maxn;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = a[maxn] < a[i] ? i : maxn;
    }
    if (a[1] > a[n])
        swap(a[1], a[n]);
    else
    {
        int temp = a[maxn];
        a[maxn] = a[n];
        a[n] = temp;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}