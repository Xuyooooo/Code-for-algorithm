#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m, l, r, ans;
int house[N];
bool check()
{
    int n1 = 2, temp = 1, n2 = 1;
    while (n1 <= n)
    {
        if (house[n1] - house[temp] >= ans)
        {
            temp = n1;
            n2++;
        }
        n1++;
    }
    return n2 >= m;
}
int main()
{
    int minn = 1e9, maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> house[i];
        minn = min(minn, house[i]);
        maxn = max(maxn, house[i]);
    }
    l = minn, r = maxn - minn;
    sort(house + 1, house + 1 + n);
    while (l < r)
    {
        ans = l + ((r - l + 1) >> 1);
        if (check())
            l = ans;
        else
            r = ans - 1;
    }
    cout << l;
}