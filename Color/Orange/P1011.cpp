

// https://www.luogu.com.cn/problem/P1011
// 模拟，数学，找规律

//===============作者本人初始没有找到规律，只能设系数来递推===================
#include <iostream>
using namespace std;
const int N = 21;
class st
{
public:
    int on[2];
    int off[2];
    int set_off[2];
};
st station[N];
int a, x, n, m;
int main()
{
    cin >> a >> n >> m >> x;
    station[1].set_off[0] = 1;
    station[1].set_off[1] = 0;
    station[1].on[0] = 1;
    station[1].on[1] = 0;
    station[1].off[0] = 0;
    station[1].off[1] = 0;
    station[2].set_off[0] = 1;
    station[2].set_off[1] = 0;
    station[2].on[0] = 0;
    station[2].on[1] = 1;
    station[2].off[0] = 0;
    station[2].off[1] = 1;
    for (int i = 3; i <= n - 1; i++)
    {
        station[i].on[0] = station[i - 1].on[0] + station[i - 2].on[0];
        station[i].on[1] = station[i - 1].on[1] + station[i - 2].on[1];
        station[i].off[0] = station[i - 1].on[0];
        station[i].off[1] = station[i - 1].on[1];
        station[i].set_off[0] = station[i - 1].set_off[0] + station[i].on[0] - station[i].off[0];
        station[i].set_off[1] = station[i - 1].set_off[1] + station[i].on[1] - station[i].off[1];
    }
    station[n].set_off[0] = station[n].set_off[1] = 0;
    int t = 0;
    if (station[n - 1].set_off[1])
        t = (m - station[n - 1].set_off[0] * a) / station[n - 1].set_off[1];
    cout << station[x].set_off[0] * a + station[x].set_off[1] * t << '\n';
}

//==========规律：从第三站始净上车人数符合斐波那契数列===============
// #include <cstdio>
// using namespace std;
// int a, n, m, x, u = 1, z, y;
// int main()
// {
//     scanf("%d %d %d %d", &a, &n, &m, &x);
//     if (n <= 5)
//     {
//         if (n == 2 || n == 3)
//             printf("%d", a);
//         else if (n == 4)
//         {
//             if (x == 1 || x == 2)
//                 printf("%d", a);
//             else if (x == 3)
//                 printf("%d", a * 2);
//         }
//         else if (n == 5)
//         {
//             if (x == 1 || x == 2)
//                 printf("%d", a);
//             else if (x == 3)
//                 printf("%d", a * 2);
//             else if (x == 4)
//                 printf("%d", (m - a * 3) / 2 + a * 2);
//         }
//     }
//     else
//     {
//         int p = 1, q = 0, k = 0, sum1 = 0;
//         for (int i = 1; i <= n - 5; i++)
//         {
//             k = p + q;
//             sum1 += k;
//             p = q;
//             q = k;
//         }
//         int s1 = sum1 + 2;
//         int e = 0, t = 1, g = 0, sum2 = 0;
//         for (int i = 1; i <= n - 5; i++)
//         {
//             g = e + t;
//             sum2 += g;
//             e = t;
//             t = g;
//         }
//         int s2 = sum2 + 1;
//         int S = (m - s1 * a) / s2;
//         q = k = e = g = sum1 = sum2 = 0;
//         p = t = 1;
//         if (x <= 5)
//         {
//             if (x == 1 || x == 2)
//                 printf("%d", a);
//             else if (x == 3)
//                 printf("%d", a * 2);
//             else if (x == 4)
//                 printf("%d", S + a * 2);
//             else
//                 printf("%d", S * 2 + a * 3);
//         }
//         else
//         {
//             for (int i = 1; i <= x - 4; i++)
//             {
//                 k = p + q;
//                 sum1 += k;
//                 p = q;
//                 q = k;
//             }
//             sum1 += 2;
//             for (int i = 1; i <= x - 4; i++)
//             {
//                 g = e + t;
//                 sum2 += g;
//                 e = t;
//                 t = g;
//             }
//             sum2 += 1;
//             printf("%d", sum1 * a + sum2 * S);
//         }
//     }
//     return 0;
// }
