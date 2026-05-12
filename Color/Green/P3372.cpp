// https://www.luogu.com.cn/problem/P3372
// 树状数组板子(区间修改+区间查询)
#include <iostream>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
#define lowbit(x) ((x) & -(x))
ll tree1[N], tree2[N]; // 两个树状数组
int n, m;
void update1(ll x, ll d)
{
    while (x <= N)
    {
        tree1[x] += d;
        x += lowbit(x);
    }
}
void update2(ll x, ll d)
{
    while (x <= N)
    {
        tree2[x] += d;
        x += lowbit(x);
    }
}
ll sum1(ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree1[x];
        x -= lowbit(x);
    }
    return ans;
}
ll sum2(ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree2[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    ll old = 0, a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;            // 输入每个初始值
        update1(i, a - old); // 差分数组原理，初始化
        update2(i, (i - 1) * (a - old));
        old = a;
    }
    while (m--)
    {
        ll q, l, r, d;
        cin >> q;
        if (q == 1)
        {
            cin >> l >> r >> d;
            update1(l, d); // 第一个树状数组
            update1(r + 1, -d);
            update2(l, d * (l - 1)); // 第二个树状数组
            update2(r + 1, -d * r);
        }
        else
        { // 区间查询
            cin >> l >> r;
            cout << r * sum1(r) - sum2(r) - (l - 1) * sum1(l - 1) + sum2(l - 1) << '\n';
        }
    }
    return 0;
}