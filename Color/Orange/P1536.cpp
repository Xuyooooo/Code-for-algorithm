// https://www.luogu.com.cn/problem/P1536

#include <iostream>
using namespace std;
const int N = 1010;
int connect[N];
int n, m, x, y;
;
void init()
{
    for (int i = 1; i <= n; i++)
        connect[i] = i;
}
int query(int x)
{
    return connect[x] == x ? x : (query(connect[x]));
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    if (a != b)
        connect[a] = connect[b];
}
int main()
{
    while (true)
    {
        int ans = 0;
        cin >> n;
        if (n == 0)
            return 0;
        cin >> m;
        init();
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            merge(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            if (query(i) == i)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}