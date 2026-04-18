// https://www.luogu.com.cn/problem/P8218
// 求区间和
// 前缀和、差分

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int cf[N];
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        cf[i] = cf[i - 1] + temp;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << cf[r] - cf[l - 1] << endl;
    }
    return 0;
}