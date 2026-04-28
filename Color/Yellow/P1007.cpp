// https://www.luogu.com.cn/problem/P1007

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 5e3 + 10;
int solider[N];
int l, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int minn = 0, max_l = 0, min_r, mid;
    cin >> l >> n;
    min_r = n + 1;
    solider[min_r] = l + 1;
    mid = l / 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> solider[i];
        if (solider[i] <= mid)
            max_l = solider[max_l] < solider[i] ? i : max_l;
        else
            min_r = solider[min_r] > solider[i] ? i : min_r;
    }
    if (fabs(mid - solider[max_l]) >= fabs(mid - solider[min_r]))
        minn = l - solider[min_r] + 1;
    else
        minn = solider[max_l];
    cout << minn << '\n';
    return 0;
}