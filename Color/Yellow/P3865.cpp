// https://www.luogu.com.cn/problem/P3865
// RMQ问题，ST表
// 查询区间最值模板

#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int dp_max[N][20]; // dp_min[N][20];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        dp_max[i][0] = a[i];
        // dp_min[i][0] = a[i];
    }
    int p = log2(n);
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j + (1 << i) <= n + 1; j++) // 注意这里是n+1，而不是n，因为下标从1开始算起
        {
            dp_max[j][i] = max(dp_max[j][i - 1], dp_max[j + (1 << (i - 1))][i - 1]); // 左边一段从l开始，右边一段以r结束，刚好覆盖，第二个区间不可以以l+2的k次方为起点，会越界
            // dp_min[i][j] = max(dp_min[i][j - 1], dp_min[i + 1 >> (j - 1)][j - 1]);
        }
    }
}
int find_ans(int l, int r)
{
    int k = log2(r - l + 1);                                // 算长度需要加1
    int x = max(dp_max[l][k], dp_max[r - (1 << k) + 1][k]); // 注意这里是r减..还要加1
    // int y = min(dp_min[l][k], dp_min[r - 1 << k + 1][k]);
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << find_ans(l, r) << '\n';
    }
}