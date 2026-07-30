// https://www.luogu.com.cn/problem/P1496

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    long long l, r;
};
bool cmp(const Interval &A, const Interval &B)
{
    if (A.l != B.l)
        return A.l < B.l;
    return A.r < B.r;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    vector<Interval> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a.begin(), a.end(), cmp);
    long long total_len = 0;
    long long L = a[0].l;
    long long R = a[0].r;

    for (int i = 1; i < n; i++)
    {
        if (a[i].l <= R)
        {
            R = max(R, a[i].r);
        }
        else
        {
            total_len += (R - L);
            L = a[i].l;
            R = a[i].r;
        }
    }
    total_len += (R - L);

    cout << total_len << "\n";

    return 0;
}
