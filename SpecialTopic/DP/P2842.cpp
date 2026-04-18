// https://www.luogu.com.cn/problem/P2842
// DP

#include <iostream>
using namespace std;
const int N = 10010;
int dp[N];
int sort[N];
int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        sort[temp] = 1;
    }
    for (int i = 1; i <= w; i++)
    {
        if (sort[i])
            dp[i] = 1;
        else
            dp[i] = dp[i - 1] + 1;
    }
    cout << dp[w] << endl;
    return 0;
}