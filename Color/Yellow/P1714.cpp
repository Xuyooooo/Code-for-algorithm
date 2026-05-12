// https://www.luogu.com.cn/problem/P1714

// https://www.luogu.com.cn/problem/P1816
// 经典RMQ，ST表，线段树

// #include <iostream>
// #include <cmath>
// using namespace std;
// const int M = 1e5 + 10;
// int bill[M];
// int dp_min[M][20];
// int m, n;
// void init()
// {
//     for (int i = 1; i <= m; i++)
//         dp_min[i][0] = bill[i];
//     int p = log2(m);
//     for (int j = 1; j <= p; j++)
//     {
//         for (int i = 1; i + (1 << j) <= m + 1; i++)
//         {
//             dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
//         }
//     }
// }
// int get_ans(int l, int r)
// {
//     int k = log2(r - l + 1);
//     int x = min(dp_min[l][k], dp_min[r - (1 << k) + 1][k]);
//     return x;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> m >> n;
//     for (int i = 1; i <= m; i++)
//         cin >> bill[i];
//     init();
//     for (int i = 1; i <= n; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         cout << get_ans(l, r) << ' ';
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 5e5 + 1;
int tree[N << 2];
int in[N];
int m, n, a, b;

void push_up(int rt)
{
    tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = in[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
    {
        return tree[rt];
    }
    int res = 1e5;
    int mid = l + ((r - l) >> 1);
    if (L <= mid)
    {
        res = min(res, query(rt << 1, l, mid, L, R));
    }
    if (R > mid)
    {
        res = min(res, query(rt << 1 | 1, mid + 1, r, L, R));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> in[i];
    build(1, 1, m);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout << query(1, 1, m, a, b) << ' ';
    }
    return 0;
}