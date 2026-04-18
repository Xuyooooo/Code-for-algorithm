// https://www.luogu.com.cn/problem/P15965
// 模拟
#include <iostream>
const int N = 1010;
int colume[N];
using namespace std;
bool simulate(int n, int x)
{
    for (int i = 1; i < n; i++)
    {
        if (colume[i + 1] > colume[i] + 1)
            return false;
        else if (colume[i] - colume[i + 1] > x)
            return false;
    }
    return true;
}
int main()
{
    int t, n, x;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> x;
        for (int j = 1; j <= n; j++)
            cin >> colume[j];
        if (simulate(n, x))
            cout << "Win" << '\n';
        else
            cout << "Lose" << '\n';
    }
    return 0;
}