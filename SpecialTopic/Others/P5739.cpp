// https://www.luogu.com.cn/problem/P5739
#include <iostream>
using namespace std;
int ans[13];
int main()
{
    ans[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] * i;
    }
    cout << ans[n];
    return 0;
}