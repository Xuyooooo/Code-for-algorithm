// https://www.luogu.com.cn/problem/P3743

#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int a[N], b[N], n, p;
long long sum = 0;
double l, r, mid;
bool check(double x)
{
    double consume = 0, all = p * x;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < a[i] * x)
        {
            consume += a[i] * x - b[i];
        }
        if (consume > all)
            return false;
    }
    return consume <= all;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p)
    {
        cout << -1 << '\n';
    }
    else
    {
        l = 0, r = 1e11;
        for (int i = 1; i <= 100; i++)
        {
            mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        cout << l << '\n';
    }
    return 0;
}