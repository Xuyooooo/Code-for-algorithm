// https://www.luogu.com.cn/problem/P3373

#include <iostream>

using namespace std;
const int N = 1e5 + 1;
long long n, q, mod, opt, x, y, k;
long long a[N], tree[N << 2], lazy1[N << 2], lazy2[N << 2];
void push_up(long long rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
    tree[rt] %= mod;
}
void push_down(long long rt, long long l, long long r)
{
    long long mid = l + ((r - l) >> 1);
    if (lazy1[rt] != 1)
    {
        tree[rt << 1] *= lazy1[rt];
        tree[rt << 1] %= mod;
        lazy1[rt << 1] *= lazy1[rt];
        lazy1[rt << 1] %= mod;
        lazy2[rt << 1] *= lazy1[rt];
        lazy2[rt << 1] %= mod;

        tree[rt << 1 | 1] *= lazy1[rt];
        tree[rt << 1 | 1] %= mod;
        lazy1[rt << 1 | 1] *= lazy1[rt];
        lazy1[rt << 1 | 1] %= mod;
        lazy2[rt << 1 | 1] *= lazy1[rt];
        lazy2[rt << 1 | 1] %= mod;

        lazy1[rt] = 1;
    }
    if (lazy2[rt])
    {
        tree[rt << 1] += lazy2[rt] * (mid - l + 1);
        tree[rt << 1] %= mod;
        lazy2[rt << 1] += lazy2[rt];
        lazy2[rt << 1] %= mod;

        tree[rt << 1 | 1] += lazy2[rt] * (r - mid);
        tree[rt << 1 | 1] %= mod;
        lazy2[rt << 1 | 1] += lazy2[rt];
        lazy2[rt << 1 | 1] %= mod;

        lazy2[rt] = 0;
    }
}
void add(long long rt, long long l, long long r, long long ql, long long qr, long long v)
{
    if (l >= ql && r <= qr)
    {
        tree[rt] += v * (r - l + 1);
        tree[rt] %= mod;
        lazy2[rt] += v;
        lazy2[rt] %= mod;
        return;
    }
    push_down(rt, l, r);
    long long mid = l + ((r - l) >> 1);
    if (ql <= mid)
        add(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        add(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}
void multify(long long rt, long long l, long long r, long long ql, long long qr, long long v)
{
    if (l >= ql && r <= qr)
    {
        tree[rt] *= v;
        tree[rt] %= mod;
        lazy1[rt] *= v;
        lazy1[rt] %= mod;
        lazy2[rt] *= v;
        lazy2[rt] %= mod;
        return;
    }
    push_down(rt, l, r);
    long long mid = l + ((r - l) >> 1);
    if (ql <= mid)
        multify(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        multify(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}

long long query(long long rt, long long l, long long r, long long ql, long long qr)
{
    if (l >= ql && r <= qr)
    {
        return tree[rt] % mod;
    }
    push_down(rt, l, r);
    long long mid = l + ((r - l) >> 1);
    long long ans = 0;
    if (ql <= mid)
    {
        ans += query(rt << 1, l, mid, ql, qr);
        ans %= mod;
    }
    if (qr > mid)
    {
        ans += query(rt << 1 | 1, mid + 1, r, ql, qr);
        ans %= mod;
    }
    return ans;
}
void build(long long rt, long long l, long long r)
{
    lazy1[rt] = 1;
    if (l == r)
    {
        tree[rt] = a[l] % mod;
        return;
    }
    long long mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> mod;

    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (long long i = 1; i <= q; i++)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> k;
            multify(1, 1, n, x, y, k);
        }
        else if (opt == 2)
        {
            cin >> x >> y >> k;
            add(1, 1, n, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}