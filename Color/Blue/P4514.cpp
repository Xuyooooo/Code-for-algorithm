// https://www.luogu.com.cn/problem/P4514

#include <iostream>
using namespace std;
const int N = 2050;
int t1[N][N], t2[N][N], t3[N][N], t4[N][N];
#define lowbit(x) ((x) & -(x))
int n, m;
void update(int x, int y, int d)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        for (int j = y; j <= m; j += lowbit(j))
        {
            t1[i][j] += d;
            t2[i][j] += x * d;
            t3[i][j] += y * d;
            t4[i][j] += x * y * d;
        }
    }
}
int sum(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
            ans += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        return ans;
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    char ch[2];
    scanf("%s", ch);
    cin >> n >> m;
    while (scanf("%s", ch) != EOF)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (ch[0] == 'L')
        {
            int del;
            cin >> del;
            update(a, b, del);
            update(c + 1, d + 1, del);
            update(a, d + 1, -del);
            update(c + 1, b, -del);
        }
        else
            cout << sum(c, d) + sum(a - 1, b - 1) - sum(a - 1, d) - sum(c, b - 1) << '\n';
    }
    return 0;
}