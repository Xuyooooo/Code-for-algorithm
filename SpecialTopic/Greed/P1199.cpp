// https://www.luogu.com.cn/problem/P1199
// 贪心策略

#include <iostream>
using namespace std;
const int N = 510;
int wujiang[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            cin >> wujiang[i][j];
    }
}