// https://www.luogu.com.cn/problem/P1551

// 并查集

//==============基础并查集======================
// #include <iostream>
// using namespace std;
// const int N = 5e3 + 10;
// int person[N];
// int n, m, p;
// void init()
// {
//     for (int i = 1; i <= n; i++)
//         person[i] = i;
// }
// int query(int x)
// {
//     if (x != person[x])
//         return query(person[x]);
//     return person[x];
// }
// void merge(int x, int y)
// {
//     int a = query(x);
//     int b = query(y);
//     if (a != b)
//         person[a] = person[b];
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m >> p;
//     int x, y;
//     init();
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> x >> y;
//         merge(x, y);
//     }
//     for (int i = 1; i <= p; i++)
//     {
//         int p1, p2;
//         cin >> p1 >> p2;
//         int a = query(p1);
//         int b = query(p2);
//         if (a == b)
//             cout << "Yes" << '\n';
//         else
//             cout << "No" << '\n';
//     }
//     return 0;
// }

//==============带优化的并查集(路径压缩)===========
#include <iostream>
using namespace std;
const int N = 5e3 + 10;
int person[N];
int n, m, p;
void init()
{
    for (int i = 1; i <= n; i++)
        person[i] = i;
}
int query(int x)
{
    if (x != person[x])
        person[x] = query(person[x]); // 路径压缩，在查询i所属的集时，在返回的时候顺便把i所属的集改为根节点
    return person[x];
    // return x==person[x]?x:(perosn[x]=query(person[x]));极简写法
}
void merge(int x, int y)
{
    int a = query(x);
    int b = query(y);
    if (a != b)
        person[a] = person[b];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    int x, y;
    init();
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= p; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        int a = query(p1);
        int b = query(p2);
        if (a == b)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}

//==============并查集优化(按秩合并)(一般使用路径压缩)=============
// #include <cstdio>
// #define MAXN 5005
// int fa[MAXN], rank[MAXN];
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
//     int n, m, p, x, y;
//     scanf("%d%d%d", &n, &m, &p);
//     init(n);
//     for (int i = 0; i < m; ++i)
//     {
//         scanf("%d%d", &x, &y);
//         merge(x, y);
//     }
//     for (int i = 0; i < p; ++i)
//     {
//         scanf("%d%d", &x, &y);
//         printf("%s\n", find(x) == find(y) ? "Yes" : "No");
//     }
//     return 0;
// }