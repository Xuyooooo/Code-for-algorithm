// https://www.luogu.com.cn/problem/P4155
// 倍增、贪心、化圆为线
// 考虑从一个区间i出发，下一个区间只能从从左端点小于等于i的右端点的区间中选择，这些区间中右端点最大的区间是最优的
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 4e5 + 2;
int n, m;
class warrior
{
public:
    int id, L, R;
    bool operator<(const warrior b) const { return L < b.L; } // 这里重写了系统默认的<小于号比较规则，当两个战士对向
    // 比较大小时，执行重写的<小于号比较规则，右边的展示对象b转成bool值返回
} w[N * 2];
int n2;
int go[N][20]; // go[s][i]表示从第s个区间出发走2的i次方个最优区间后到达的区间
// 且有go[s][i]=go [go[s][i-1]] [i-1];
// 即先从s起跳，先跳2的(i-1)次方步到区间z=go[s][i-1]
// 再从z跳2的(i-1)次方步到区间go[z][i-1],一共跳了2的i次方步
void init()
{
    int nxt = 1;
    for (int i = 1; i <= n2; i++)
    {
        while (nxt <= n2 && w[nxt].L <= w[i].R)
            nxt++;
        go[i][0] = nxt - 1; // 用贪心求每一个区间的下一个区间
    }
    for (int i = 1; (1 << i) <= n; i++) // 倍增
    {
        for (int s = 1; s <= n2; s++)
        {
            go[s][i] = go[go[s][i - 1]][i - 1];
        }
    }
}
int res[N];
void getans(int x)
{
    int len = w[x].L + m, cur = x, ans = 1;
    for (int i = log2(N); i >= 0; i--)
    {
        int pos = go[cur][i];
        if (pos && w[pos].R < len)
        {
            ans += 1 << i;
            cur = pos;
        }
    }
    res[w[x].id] = ans + 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        w[i].id = i;
        cin >> w[i].L >> w[i].R;
        if (w[i].R < w[i].L)
            w[i].R += m; // 化圆为线
    }
    sort(w + 1, w + n + 1);
    n2 = n;
    for (int i = 1; i <= n; i++)
    {
        n2++;
        w[n2] = w[i];
        w[n2].L = w[i].L + m;
        w[n2].R = w[i].R + m; // 这里是复制圆圈再相接
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        getans(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}