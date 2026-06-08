// https://www.luogu.com.cn/problem/P1083

// 线段树，差分，二分

//============线段树============
// #include <iostream>
// using namespace std;
// const int N = 1e6 + 1;
// int n, m, s, d, t;
// int a[N], tree[N << 2], lazy[N << 2];
// void push_up(int rt)
// {
//     tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
// }
// void push_down(int rt, int l, int r)
// {
//     if (lazy[rt])
//     {
//         tree[rt << 1] -= lazy[rt];
//         lazy[rt << 1] += lazy[rt];
//         tree[rt << 1 | 1] -= lazy[rt];
//         lazy[rt << 1 | 1] += lazy[rt];
//         lazy[rt] = 0;
//     }
// }
// void build(int rt, int l, int r)
// {
//     if (l == r)
//     {
//         tree[rt] = a[l];
//         return;
//     }
//     int mid = l + ((r - l) >> 1);
//     build(rt << 1, l, mid);
//     build(rt << 1 | 1, mid + 1, r);
//     push_up(rt);
// }
// void update(int rt, int l, int r, int ql, int qr, int v)
// {
//     if (l >= ql && r <= qr)
//     {
//         tree[rt] -= v;
//         lazy[rt] += v;
//         return;
//     }
//     push_down(rt, l, r);
//     int mid = l + ((r - l) >> 1);
//     if (ql <= mid)
//         update(rt << 1, l, mid, ql, qr, v);
//     if (qr > mid)
//         update(rt << 1 | 1, mid + 1, r, ql, qr, v);
//     push_up(rt);
// }
// int query(int rt, int l, int r, int ql, int qr)
// {
//     if (l >= ql && r <= qr)
//     {
//         return tree[rt];
//     }
//     push_down(rt, l, r);
//     int mid = l + ((r - l) >> 1);
//     int ans = 1e9;
//     if (ql <= mid)
//         ans = min(ans, query(rt << 1, l, mid, ql, qr));
//     if (qr > mid)
//         ans = min(ans, query(rt << 1 | 1, mid + 1, r, ql, qr));
//     return ans;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     build(1, 1, n);
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> d >> s >> t;
//         if (query(1, 1, n, s, t) < d)
//         {
//             cout << -1 << '\n';
//             cout << i << '\n';
//             return 0;
//         }
//         else
//         {
//             update(1, 1, n, s, t, d);
//         }
//     }
//     cout << 0 << '\n';
//     return 0;
// }

//===============差分，二分===============
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000005;
int n, m;
long long r[N], diff[N], need[N];
struct Order
{
    int d, s, t;
} o[N];
bool check(int x)
{
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; i++)
    {
        diff[o[i].s] += o[i].d;
        diff[o[i].t + 1] -= o[i].d;
    }
    long long cur_need = 0;
    for (int i = 1; i <= n; i++)
    {
        cur_need += diff[i];
        if (cur_need > r[i])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (!(cin >> n >> m))
        return 0;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= m; i++)
        cin >> o[i].d >> o[i].s >> o[i].t;
    if (check(m))
    {
        cout << 0 << '\n';
        return 0;
    }
    int low = 1, high = m, ans = 0;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (check(mid))
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << -1 << '\n';
    cout << ans << '\n';

    return 0;
}