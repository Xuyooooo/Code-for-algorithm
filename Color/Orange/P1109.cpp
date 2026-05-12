// https://www.luogu.com.cn/problem/P1109

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 51;
int num[N], n, l, r, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    sort(num + 1, num + n + 1);
    cin >> l >> r;
    if (num[1] >= l && num[n] <= r)
    {
        cout << ans << '\n';
        return 0;
    }
    int shao = 0, duo = 0;
    for (int i = 1; i <= n; i++)
    {
        if (num[i] >= l)
            break;
        else
            shao += l - num[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if (num[i] <= r)
            break;
        else
            shao += r - num[i];
    }
    ans = max(shao, duo);
    cout << ans << '\n';
    return 0;
}