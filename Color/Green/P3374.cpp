// https://www.luogu.com.cn/problem/P3374

// 线段树，树状数组

#include <iostream>

using namespace std;

const int N = 5e5 + 1;
int tree[N << 2];
int input[N];
int n, m, opi, x, y;

void push_up(int x)
{
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = input[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void add(int rt, int l, int r, int x, int v)
{
    if (l == r)
    {
        tree[rt] += v;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (x <= mid)
        add(rt << 1, l, mid, x, v);
    else
        add(rt << 1 | 1, mid + 1, r, x, v);
    push_up(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
    {
        return tree[rt];
    }
    int mid = l + ((r - l) >> 1);
    int res = 0;
    if (L <= mid)
    {
        res += query(rt << 1, l, mid, L, R);
    }
    if (R > mid)
    {
        res += query(rt << 1 | 1, mid + 1, r, L, R);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        cin >> opi >> x >> y;
        if (opi == 1)
        {
            input[x] += y;
            add(1, 1, n, x, y);
        }
        else
        {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}