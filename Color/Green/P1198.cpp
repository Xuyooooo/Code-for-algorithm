// // https://www.luogu.com.cn/problem/P1198

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// int m, d;
// vector<int> a;
// int init_and_query(int l)
// {
//     const int N = 2e5 + 10;
//     int size = a.size();
//     int dp_max[N][20] = {0};
//     for (int i = l; i < size; i++)
//         dp_max[i][0] = a[i];
//     int p = log2(size - l);
//     for (int j = 1; j <= p; j++)
//     {
//         for (int i = l; i + (1 << j) <= size; i++)
//         {
//             dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     int x = max(dp_max[size - l][p], dp_max[size - (1 << p)][p]);
//     return x;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> m >> d;
//     int t = 0;
//     for (int i = 1; i <= m; i++)
//     {
//         char c;
//         cin >> c;
//         if (c == 'A')
//         {
//             int n;
//             cin >> n;
//             n += t;
//             n %= d;
//             a.push_back(n);
//         }
//         else
//         {
//             int l;
//             cin >> l;
//             t = init_and_query(l);
//             cout << t << '\n';
//         }
//     }
//     return 0;
// }

#include <iostream>

using namespace std;
const int N = 2e5 + 1;
int a[N], tree[N << 2];
int m, k, l, t, now;
void push_up(int rt)
{
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
void update(int rt, int l, int r, int x, int v)
{
    if (l == r)
    {
        tree[rt] = v;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if (x <= mid)
        update(rt << 1, l, mid, x, v);
    else
        update(rt << 1 | 1, mid + 1, r, x, v);
    push_up(rt);
}
int query(int rt, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
        return tree[rt];
    int mid = l + ((r - l) >> 1);
    int ans = 0;
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
    cin >> m >> k;
    now = t = 0;
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c >> l;
        if (c == 'A')
        {
            now++;
            l = (1LL * l + t) % k; // 这里要强转为long long，不然会爆int
            a[now] = l;
            update(1, 1, m, now, l);
        }
        else
        {
            t = query(1, 1, m, now - l + 1, now);
            cout << t << '\n';
        }
    }
    return 0;
}