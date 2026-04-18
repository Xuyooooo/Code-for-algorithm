// https://www.luogu.com.cn/problem/P1094

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e4 + 10;
int gift[N], ans = 0;
int main()
{
    int n, w;
    cin >> w >> n;
    int l = 1, r = n;
    for (int i = 1; i <= n; i++)
        cin >> gift[i];
    sort(gift + 1, gift + n + 1);
    while (l <= r)
    {
        if (gift[l] + gift[r] <= w)
        {
            l++;
            r--;
        }
        else
            r--;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}