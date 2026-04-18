// https://www.luogu.com.cn/problem/P5461
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1025;
bool punish[N][N];
int main()
{
    int k;
    cin >> k;
    int n = pow(2, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> punish[i][j];
    }
    return 0;
}
