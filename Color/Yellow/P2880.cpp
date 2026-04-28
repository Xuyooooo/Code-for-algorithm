// https://www.luogu.com.cn/problem/P2880
// 区间最值查询问题(Range Minimum/Maximum Query--RMQ)，
// ST算法适用于静态空间的RMQ：给定长度为n的静态数列，做m次查询，每次给定L，R<=n，查询数列区间[L,R]内的最值
// ST算法的原理：一个大区间若能被两个小区间覆盖，那么大区间的最值等于两个小区间的最值(两个小区间重合不影响结果)
// 那么包括两个步骤：1.把整个数列分为很多个小区间，并提前计算出每个小区间的最值
// 2.对任意区间的最值查询，找到覆盖它的两个小区间，由两个小区间的最值算出答案
// 本题采用倍增法分块
// 定义dp[s][k]表示左端点为s，区间长度为2的k次方的区间最值，则存在递推关系
// dp[s][k]=min{dp[s][k-1],dp[s+1<<(k-1)][k-1]};

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 5e4 + 5;
int n, m;
int a[N], dp_max[N][22], dp_min[N][22]; // 以2为底的对数，向下取整
int LOG2[N];
void st_init()
{
    LOG2[0] = -1;
    for (int i = 1; i <= N; i++)
    {
        LOG2[i] = LOG2[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp_min[i][0] = a[i];
        dp_max[i][0] = a[i];
    }
    int p = log2(n); // 计算区间的最大范围
    // int p = (int)(log(double(n)) / log(2.0));
    for (int k = 1; k <= p; k++)
    {
        for (int s = 1; s + (1 << k) <= n + 1; s++)
        {
            dp_max[s][k] = max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
            dp_min[s][k] = min(dp_min[s][k - 1], dp_min[s + (1 << (k - 1))][k - 1]);
        }
    } // 由公式计算每个区间的最小值和最大值
}
int st_query(int L, int R)
{
    int k = log2(R - L + 1);
    // int k = (int)(log(double(R - L + 1)) / log(2.0));
    // int k = LOG2[R - L + 1];
    int x = max(dp_max[L][k], dp_max[R - (1 << k) + 1][k]); // 右边的不能改为L+...,必须保证两个区间覆盖
    int y = min(dp_min[L][k], dp_min[R - (1 << k) + 1][k]);
    return x - y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    st_init();
    for (int i = 1; i <= m; i++)
    {
        int L, R;
        cin >> L >> R;
        cout << st_query(L, R) << '\n';
    }
    return 0;
}
