// https://www.luogu.com.cn/problem/P1198

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int m, d;
vector<int> a;
int init_and_query(int l)
{
    const int N = 2e5 + 10;
    int size = a.size();
    int dp_max[N][20] = {0};
    for (int i = l; i < size; i++)
        dp_max[i][0] = a[i];
    int p = log2(size - l);
    for (int j = 1; j <= p; j++)
    {
        for (int i = l; i + (1 << j) <= size; i++)
        {
            dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
        }
    }
    int x = max(dp_max[size - l][p], dp_max[size - (1 << p)][p]);
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> d;
    int t = 0;
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            int n;
            cin >> n;
            n += t;
            n %= d;
            a.push_back(n);
        }
        else
        {
            int l;
            cin >> l;
            t = init_and_query(l);
            cout << t << '\n';
        }
    }
    return 0;
}