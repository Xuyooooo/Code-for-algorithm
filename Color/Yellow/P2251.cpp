// https://www.luogu.com.cn/problem/P2251
// 滑动窗口，单调队列,RMQ,ST表，线段树

//===================滑动窗口==============
// #include <iostream>
// #include <deque>
// using namespace std;
// const int N = 1e5 + 10;
// int A[N];
// int n, m;
// int main()
// {
//     deque<int> b;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> A[i];
//     int i = 1;
//     while (i <= n)
//     {
//         while (!b.empty() && A[b.back()] > A[i])
//             b.pop_back();
//         b.push_back(i);
//         if (i >= m)
//         {
//             while (!b.empty() && i - b.front() >= m)
//                 b.pop_front();
//             cout << A[b.front()] << '\n';
//         }
//         i++;
//     }
//     return 0;
// }

//================ST表(RMQ)==================
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int A[N];
int dp_min[N][20];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
        dp_min[i][0] = A[i];
    int p = log2(n);
    for (int j = 1; j <= p; j++)
    {
        for (int i = 1; i + (1 << j) <= n + 1; i++)
        {
            dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int get_ans(int l, int r)
{
    int k = log2(r - l + 1);
    int x = min(dp_min[l][k], dp_min[r - (1 << k) + 1][k]);
    return x;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    init();
    for (int r = m; r <= n; r++)
    {
        int l = r - m + 1;
        cout << get_ans(l, r) << '\n';
    }
    return 0;
}

//==============线段树(来源于题解区，据说是线段树裸题)=================
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int oo = 0x7fffffff;
// int n, m;
// int a[100005];
// int Minn[100005 * 4];
// void create(int root, int l, int r)
// {
//     if (l == r)
//     {
//         Minn[root] = a[l];
//         return;
//     }
//     int mid = (l + r) / 2;
//     create(root << 1, l, mid);
//     create(root << 1 | 1, mid + 1, r);
//     Minn[root] = min(Minn[root << 1], Minn[root << 1 | 1]);
// }
// int query(int root, int l, int r, int x, int y)
// {
//     if (l > y || x > r)
//         return oo;
//     if (l >= x && r <= y)
//         return Minn[root];
//     int mid = (l + r) / 2;
//     int k = oo;
//     if (y < mid)
//         k = min(k, query(root << 1, l, mid, x, y));
//     else if (x > mid)
//         k = min(query(root << 1 | 1, mid + 1, r, x, y), k);
//     else
//         k = min(query(root << 1 | 1, mid + 1, r, x, y), query(root << 1, l, mid, x, y));
//     return k;
// }
// int main()
// {
//     fill(Minn, Minn + 100005, oo);
//     cin >> n >> m;
//     int d = 1;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     create(1, 1, n);
//     for (int i = 1; i <= n - m + 1; i++)
//     {
//         cout << query(1, 1, n, i, i + m - 1) << endl;
//     }
//     return 0;
// }
