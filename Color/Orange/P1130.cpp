// https://www.luogu.com.cn/problem/P1130

#include <iostream>
using namespace std;
const int N = 2010;
int a[N][N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    return 0;
}