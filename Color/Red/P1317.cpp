// https://www.luogu.com.cn/problem/P1317
// 模拟，合并数组

#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int a[N], n, ans;
int main()
{
    int temp, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (a[k - 1] != temp)
        {
            a[k++] = temp;
        }
    }
    for (int i = 2; i < k; i++)
    {
        if (a[i - 1] > a[i] && a[i + 1] > a[i])
            ans++;
    }
    cout << ans << '\n';
    return 0;
}