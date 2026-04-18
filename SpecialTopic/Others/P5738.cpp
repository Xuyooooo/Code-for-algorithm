// https://www.luogu.com.cn/problem/P5738
// 模拟

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 21;
int score[N];
int main()
{
    int n, m;
    double maxm = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        double sum = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> score[j];
        }
        sort(score + 1, score + m + 1);
        for (int j = 2; j < m; j++)
            sum += score[j];
        if (maxm < sum / (m - 2))
            maxm = sum / (m - 2);
    }
    cout << fixed << setprecision(2) << maxm << '\n';
    return 0;
}