// https://www.luogu.com.cn/problem/P4995
// 贪心策略
// 自定义比较函数
// 双指针

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 301;
int stone[N];
long long ans = 0;
bool com(int a, int b)
{
    return a < b;
}
int main()
{
    int n, now = 1, num = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stone[i];
    sort(stone + 1, stone + n + 1, com);
    ans += stone[n] * stone[n];
    for (int i = n; now != i;)
    {
        ans += pow(stone[i] - stone[now], 2);
        if (num++ & 1)
            i--;
        else
            now++;
    }
    cout << ans << '\n';
    return 0;
}