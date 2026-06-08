// https://www.luogu.com.cn/problem/P1531

#include <iostream>
using namespace std;
const int N = 2e5 + 1;
long long a[N], tree[N << 2], lazy[N << 2];
long long n, m, b, d;
char c;
void push_up(int rt)
{
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
void update(long long rt, long long l, long long r, long long x, long long v)
{
    if (l == r)
    {
        tree[rt] = max(tree[rt], v);
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (x <= mid)
        update(rt << 1, l, mid, x, v);
    else
        update(rt << 1 | 1, mid + 1, r, x, v);
    push_up(rt);
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
long long query(int rt, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
        return tree[rt];
    int mid = l + ((r - l) >> 1);
    long long ans = 0;
    if (ql <= mid)
        ans = max(ans, query(rt << 1, l, mid, ql, qr));
    if (qr > mid)
        ans = max(ans, query(rt << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> b >> d;
        if (c == 'Q')
            cout << query(1, 1, n, b, d) << '\n';
        else
            update(1, 1, n, b, d);
    }
    return 0;
}