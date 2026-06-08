// https://www.luogu.com.cn/problem/P1714

// 线段树，有错误
// #include <iostream>
// using namespace std;
// const int N = 5e5 + 1;
// long long a[N], tree[N << 2];
// long long ans, n, m;
// void push_up(int rt)
// {
//     tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
//     tree[rt] = max(tree[rt << 1] + tree[rt << 1 | 1], tree[rt]);
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
// long long query(int rt, int l, int r, int ql, int qr)
// {
//     if (l >= ql && r <= qr)
//         return tree[rt];
//     int mid = l + ((r - l) >> 1);
//     long long res = -1e8;
//     if (ql <= mid)
//         res = max(res, query(rt << 1, l, mid, ql, qr));
//     if (qr > mid)
//         res = max(res, query(rt << 1 | 1, mid + 1, r, ql, qr));
//     return res;
// }
// int main()
// {
//     ans = -1e8;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     build(1, 1, n);
//     for (int i = 1; i <= n - m + 1; i++)
//     {
//         ans = max(ans, query(1, 1, n, i, i + m - 1));
//     }
//     cout << ans << '\n';
//     return 0;
// }

//=================单调队列实现滑动窗口===========
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int N = 5e5 + 5;
long long sum[N];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        long long val;
        cin >> val;
        sum[i] = sum[i - 1] + val;
    }
    deque<int> q;
    q.push_back(0);
    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && q.front() < i - m)
        {
            q.pop_front();
        }
        ans = max(ans, sum[i] - sum[q.front()]);
        while (!q.empty() && sum[q.back()] >= sum[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << ans << '\n';
    return 0;
}