// https://www.luogu.com.cn/problem/P3372
// 树状数组板子(区间修改+区间查询)
// #include <iostream>
// using namespace std;
// #define ll long long
// const int N = 1e5 + 10;
// #define lowbit(x) ((x) & -(x))
// ll tree1[N], tree2[N]; // 两个树状数组
// int n, m;
// void update1(ll x, ll d)
// {
//     while (x <= N)
//     {
//         tree1[x] += d;
//         x += lowbit(x);
//     }
// }
// void update2(ll x, ll d)
// {
//     while (x <= N)
//     {
//         tree2[x] += d;
//         x += lowbit(x);
//     }
// }
// ll sum1(ll x)
// {
//     ll ans = 0;
//     while (x > 0)
//     {
//         ans += tree1[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// ll sum2(ll x)
// {
//     ll ans = 0;
//     while (x > 0)
//     {
//         ans += tree2[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// int main()
// {
//     cin >> n >> m;
//     ll old = 0, a;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a;            // 输入每个初始值
//         update1(i, a - old); // 差分数组原理，初始化
//         update2(i, (i - 1) * (a - old));
//         old = a;
//     }
//     while (m--)
//     {
//         ll q, l, r, d;
//         cin >> q;
//         if (q == 1)
//         {
//             cin >> l >> r >> d;
//             update1(l, d); // 第一个树状数组
//             update1(r + 1, -d);
//             update2(l, d * (l - 1)); // 第二个树状数组
//             update2(r + 1, -d * r);
//         }
//         else
//         { // 区间查询
//             cin >> l >> r;
//             cout << r * sum1(r) - sum2(r) - (l - 1) * sum1(l - 1) + sum2(l - 1) << '\n';
//         }
//     }
//     return 0;
// }

// 线段树实现区间修改+区间查询，关键在于懒标记，懒标记模板

#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll tree[N << 2];
ll lazy[N << 2];
ll a[N];
int n, m;

void push_up(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
// 这是懒标记的核心。当访问到一个节点并且它具有标记时，把标记传给儿子
void push_down(int rt, int l, int r)
{
    if (lazy[rt] != 0)
    {
        int mid = l + ((r - l) >> 1);

        tree[rt << 1] += lazy[rt] * (mid - l + 1);
        lazy[rt << 1] += lazy[rt];

        tree[rt << 1 | 1] += lazy[rt] * (r - mid);
        lazy[rt << 1 | 1] += lazy[rt];

        lazy[rt] = 0;
    }
}

void update(int rt, int l, int r, int ql, int qr, ll v)
{
    if (ql <= l && r <= qr)
    {
        tree[rt] += v * (r - l + 1);
        lazy[rt] += v;
        return;
    }
    push_down(rt, l, r);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        update(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}

ll query(int rt, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    push_down(rt, l, r); // 注意这里要传标记
    int mid = l + ((r - l) >> 1);
    ll sum = 0;
    if (ql <= mid)
        sum += query(rt << 1, l, mid, ql, qr);
    if (qr > mid)
        sum += query(rt << 1 | 1, mid + 1, r, ql, qr);
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n >> m))
        return 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    while (m--)
    {
        int opi, x, y;
        ll k;
        cin >> opi;
        if (opi == 1)
        {
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}