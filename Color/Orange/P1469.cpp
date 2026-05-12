// https://www.luogu.com.cn/problem/P1469

// 异或
// 此题有点恶心，必须得关闭输入输出流才能过
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        ans ^= a;
    }
    cout << ans << '\n';
    return 0;
}