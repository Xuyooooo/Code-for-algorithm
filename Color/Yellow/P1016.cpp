// https://www.luogu.com.cn/problem/P1016
// 贪心

// #include <iostream>
// using namespace std;
// const int N = 7;
// class station
// {
// public:
//     int d;
//     int p;
// } st[N];
// int n, s, c, l, p0;
// bool ok = true;
// int main()
// {

//     cin >> s >> c >> l >> p0 >> n;
//     int max_s = c * l;
//     st[0].d = 0;
//     st[0].p = p0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> st[i].d >> st[i].p;
//         if (st[i].d - st[i].p > max_s)
//             ok = false;
//     }
//     if (s - st[n].d > max_s)
//         ok = false;
//     if (!ok)
//     {
//         cout << "No Solution" << '\n';
//     }
//     else
//     {
//         int pre = 0, now = 1, ans = (st[1].d - st[0].d) * st[0].p;
//         while (st[now].d - st[pre].p <= max_s)
//         {
//             now++;
//         }
//         for (int i = pre + 1; i <= now - 2; i++)
//         {
//             if (st[pre].p <= st[i].p)
//                 ans += (st[i + 1].d - st[i].d) * st[pre].p;
//             else
//                 ans += (st[i + 1].d - st[i].d) * st[i].p;
//         }
//     }
//     return 0;
// }

//=======作者自己想的贪心，感觉有点奇怪，虽然测试点都过了===============

#include <iostream>
#include <iomanip>
using namespace std;
const int N = 8;
class station
{
public:
    double d;
    double p;
} st[N];
int n;
double ans = 10000.0, s, c, l, p0, max_s;
bool ok = true;

// 思路：在当前站中下一站的范围是有限的，依次去符合条件的加油站
// 如果下一站油价比当前站贵，当前站应该尽可能多加油(但要确保最后抵达终点油消耗完了)
// 反之，当前站只用加相应的路程的油

//............总感觉思路有点奇葩
void dfs(int now, double V_rest, double M_consume) // now代表当前汽车所处位置，V_rest代表在当前位置加油前还剩多少油，M_consume代表目前花费多少
{
    if (now == n + 1)
    {
        if (ans > M_consume)
            ans = M_consume;
        return;
    }
    for (int i = now + 1; i <= n + 1; i++)
    {
        if (st[i].d - st[now].d <= max_s)
        {
            double s1 = st[i].d - st[now].d;
            double s2 = st[n + 1].d - st[now].d;
            if (st[i].p > st[now].p)
            {
                if (s2 >= max_s)
                    dfs(i, c - s1 / l, M_consume + (c - V_rest) * st[now].p);
                else
                    dfs(i, s2 / l - s1 / l, M_consume + (s2 / l - V_rest) * st[now].p);
            }
            else
            {
                dfs(i, 0, M_consume + st[now].p * s1 / l);
            }
        }
        else
            break;
    }
}
int main()
{
    cin >> s >> c >> l >> p0 >> n;
    max_s = c * l;
    st[0].d = 0;
    st[0].p = p0;
    st[n + 1].d = s;
    st[n + 1].p = 10100;
    for (int i = 1; i <= n; i++)
    {
        cin >> st[i].d >> st[i].p;
        if (st[i].d - st[i - 1].d > max_s)
            ok = false;
    }
    if (st[n + 1].d - st[n].d > max_s)
        ok = false;
    if (!ok)
    {
        cout << "No Solution" << '\n';
    }
    else
    {
        dfs(0, 0, 0);
        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}