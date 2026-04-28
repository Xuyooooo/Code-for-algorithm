// https://www.luogu.com.cn/problem/P1031
// 均分纸牌

#include <iostream>
#include <cmath>
using namespace std;
const int N = 110;
int a[N], dp[N], n;

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int average = sum / n;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + a[i] - average;
        if (dp[i])
            sum += 1;
    }
    cout << sum << '\n';
    return 0;
}