// https://www.luogu.com.cn/problem/P1003
// 枚举、栈

#include <iostream>
using namespace std;
const int N = 1e4 + 10;
class point
{
public:
    int x;
    int y;
};
class a
{
public:
    point weizhi[2];
};
a location[N];
int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        location[i].weizhi[0].x = a;
        location[i].weizhi[0].y = b;
        location[i].weizhi[1].x = a + g;
        location[i].weizhi[1].y = b + k;
    }
    cin >> x >> y;
    for (int i = n; i >= 1; i--)
    {
        if (x >= location[i].weizhi[0].x && x <= location[i].weizhi[1].x && y >= location[i].weizhi[0].y && y <= location[i].weizhi[1].y)
        {
            cout << i << '\n';
            break;
        }
        else if (i == 1)
            cout << -1 << '\n';
    }
    return 0;
}