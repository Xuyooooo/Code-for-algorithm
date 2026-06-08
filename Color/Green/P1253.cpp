// https://www.luogu.com.cn/problem/P1253

#include <iostream>
using namespace std;
const int N = 1e6 + 1;
const long long INF = 1e18;
int n, q, opt, x, y;
long long v;
long long a[N], tree[N << 2], lazy1[N << 2], lazy2[N << 2];
void push_up(int rt)
{
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
void push_down(int rt)
{
    if (lazy1[rt] != -INF)
    {
        tree[rt << 1] = lazy1[rt];
        lazy1[rt << 1] = lazy1[rt];
        lazy2[rt << 1] = 0;
        tree[rt << 1 | 1] = lazy1[rt];
        lazy1[rt << 1 | 1] = lazy1[rt];
        lazy2[rt << 1 | 1] = 0;
        lazy1[rt] = -INF;
    }
    if (lazy2[rt] != 0)
    {
        tree[rt << 1] += lazy2[rt];
        if (lazy1[rt << 1] != -INF)
            lazy1[rt << 1] += lazy2[rt];
        else
            lazy2[rt << 1] += lazy2[rt];
        tree[rt << 1 | 1] += lazy2[rt];
        if (lazy1[rt << 1 | 1] != -INF)
            lazy1[rt << 1 | 1] += lazy2[rt];
        else
            lazy2[rt << 1 | 1] += lazy2[rt];
        lazy2[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    lazy1[rt] = -INF;
    lazy2[rt] = 0;
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
void update1(int rt, int l, int r, int ql, int qr, long long v)
{
    if (l >= ql && r <= qr)
    {
        tree[rt] = v;
        lazy1[rt] = v;
        lazy2[rt] = 0; // 这里处理两个懒标记是关键
        return;
    }
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update1(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        update1(rt << 1 | 1, mid + 1, r, ql, qr, v); // 修复：右半区间是 mid + 1 到 r
    push_up(rt);
}
void update2(int rt, int l, int r, int ql, int qr, long long v)
{
    if (l >= ql && r <= qr)
    {
        tree[rt] += v;
        if (lazy1[rt] != -INF)
            lazy1[rt] += v;
        else
            lazy2[rt] += v;
        return;
    }
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update2(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        update2(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}
long long query(int rt, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
        return tree[rt];
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    long long ans = -INF;
    if (ql <= mid)
        ans = max(ans, query(rt << 1, l, mid, ql, qr));
    if (qr > mid)
        ans = max(ans, query(rt << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            cin >> v;
            update1(1, 1, n, x, y, v);
        }
        else if (opt == 2)
        {
            cin >> v;
            update2(1, 1, n, x, y, v);
        }
        else if (opt == 3)
        {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}