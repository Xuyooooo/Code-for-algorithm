// https://www.luogu.com.cn/problem/P3958

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// const int N = 1e3 + 10;
// int link[N];
// int n, h, r;
// class cheese
// {
// public:
//     int x;
//     int y;
//     int z;
// } input[N];
// bool com(cheese a, cheese b)
// {
//     if (a.z <= b.z)
//         return true;
//     return false;
// }
// void init()
// {
//     for (int i = 1; i <= n; i++)
//         link[i] = i;
// }
// double dist(cheese a, cheese b)
// {
//     return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
// }
// void merge()
// {
// }
// int main()
// {
//     int T;
//     cin >> T;
//     for (int i = 1; i <= T; i++)
//     {
//         int size = 0;
//         cin >> n >> h >> r;
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> input[i].x >> input[i].y >> input[i].z;
//             if (input[i].z <= r)
//                 size++;
//         }
//         if (2 * r >= h)
//             cout << "Yes" << '\n';
//         else
//         {
//             if (!size)
//                 cout << "No" << '\n';
//             else
//             {
//                 init();
//                 sort(input + 1, input + n + 1);
//                 for (int j = size + 1; j <= n; j++)
//                 {
//                     for (int k = 1; i <= size; k++)
//                     {
//                         if (dist(input[j], input[k])<=r)
//                         {

//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

//=============并查集===================
// #include <cstdio>
// #include <cstring>
// #define MAXN 1005
// typedef long long ll;
// int fa[MAXN], rank[MAXN];
// ll X[MAXN], Y[MAXN], Z[MAXN];
// inline bool next_to(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2, ll r)
// {
//     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
//     // 判断两个空洞是否相交或相切
// }
// inline void init(int n)
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         fa[i] = i;
//         rank[i] = 1;
//     }
// }
// int find(int x)
// {
//     return x == fa[x] ? x : (fa[x] = find(fa[x]));
// }
// inline void merge(int i, int j)
// {
//     int x = find(i), y = find(j);
//     if (rank[x] <= rank[y])
//         fa[x] = y;
//     else
//         fa[y] = x;
//     if (rank[x] == rank[y] && x != y)
//         rank[y]++;
// }
// int main()
// {
//     int T, n, h;
//     ll r;
//     scanf("%d", &T);
//     for (int I = 0; I < T; ++I)
//     {
//         memset(X, 0, sizeof(X));
//         memset(Y, 0, sizeof(Y));
//         memset(Z, 0, sizeof(Z));
//         scanf("%d%d%lld", &n, &h, &r);
//         init(n);
//         fa[1001] = 1001; // 用1001代表底部
//         fa[1002] = 1002; // 用1002代表顶部
//         for (int i = 1; i <= n; i++)
//         {
//             scanf("%lld%lld%lld", X + i, Y + i, Z + i);
//             if (Z[i] <= r)
//                 merge(i, 1001); // 与底部接触的空洞与底部合并
//             if (Z[i] + r >= h)
//                 merge(i, 1002); // 与顶部接触的空洞与顶部合并
//         }
//         for (int i = 1; i <= n; ++i)
//         {
//             for (int j = i + 1; j <= n; ++j)
//             {
//                 if (next_to(X[i], Y[i], Z[i], X[j], Y[j], Z[j], r))
//                     merge(i, j); // 遍历所有空洞，合并相交或相切的球
//             }
//         }
//         printf("%s\n", find(1001) == find(1002) ? "Yes" : "No");
//     }
//     return 0;
// }

//===============DFS=======================
#include <bits/stdc++.h>
using namespace std;
int n, v[1005], t, ok;
double x[1005], y[1005], z[1005], h, r;
bool e(int i, int j)
{
    double dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
    return dis <= 4 * r * r;
}
void dfs(int k)
{
    if (ok)
        return;
    if (z[k] + r >= h)
    {
        ok = 1;
        return;
    }
    v[k] = 1;
    for (int i = 1; i <= n; i++)
        if (!v[i] && e(i, k))
            dfs(i); // 因为深搜条件的控制，这里不需要回溯
}
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(v, 0, sizeof(v)); // 记得清零
        ok = 0;
        cin >> n >> h >> r;
        for (int j = 1; j <= n; j++)
            cin >> x[j] >> y[j] >> z[j];
        for (int j = 1; j <= n; j++)
            if (z[j] - r <= 0)
                dfs(j);
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
