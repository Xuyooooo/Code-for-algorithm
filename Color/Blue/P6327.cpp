// https://www.luogu.com.cn/problem/P6327

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 2e5 + 1;

class Node
{
public:
    double s, c;
} tree[N << 2];
int lazy[N << 2];
double a[N];
int opt, l, r, v, n, m;

void push_up(int rt)
{
    tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;
    tree[rt].c = tree[rt << 1].c + tree[rt << 1 | 1].c;
}
void apply(int rt, int v)
{
    double sv = sin(v);
    double cv = cos(v);
    double s = tree[rt].s;
    double c = tree[rt].c;
    tree[rt].s = s * cv + c * sv;
    tree[rt].c = c * cv - s * sv;
    lazy[rt] += v;
}
void push_down(int rt)
{
    if (lazy[rt] != 0)
    {
        apply(rt << 1, lazy[rt]);
        apply(rt << 1 | 1, lazy[rt]);
        lazy[rt] = 0;
    }
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt].s = sin(a[l]);
        tree[rt].c = cos(a[l]);
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int ql, int qr, int v)
{
    if (l >= ql && r <= qr)
    {
        apply(rt, v);
        return;
    }
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid)
        update(rt << 1, l, mid, ql, qr, v);
    if (qr > mid)
        update(rt << 1 | 1, mid + 1, r, ql, qr, v);
    push_up(rt);
}
double query(int rt, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
        return tree[rt].s;
    push_down(rt);
    int mid = l + ((r - l) >> 1);
    double res = 0;
    if (ql <= mid)
        res += query(rt << 1, l, mid, ql, qr);
    if (qr > mid)
        res += query(rt << 1 | 1, mid + 1, r, ql, qr);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        }
        else
        {
            cin >> l >> r;
            cout << fixed << setprecision(1) << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}