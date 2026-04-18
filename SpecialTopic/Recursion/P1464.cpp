// #include <iostream>
// using namespace std;
// long long w(int a, int b, int c)
// {
//     if (a <= 0 || b <= 0 || c <= 0)
//         return 1;
//     if (a > 20 || b > 20 || c > 20)
//         return w(20, 20, 20);
//     if (a < b && b < c)
//         return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//     return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
// }
// int main()
// {
//     while (1)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         if (a == -1 && b == -1 && c == -1)
//             break;
//         cout << "w(" << a << ',' << b << ',' << c << ")=" << w(a, b, c);
//     }
// }

// 常规递归时间会超，需要采用记忆化的方式记录值
#include <cstdio>
#include <iostream>
#define llx long long
using namespace std;
llx f[40][40][40], a, b, c;
llx fun(llx x, llx y, llx z)
{
    if (x <= 20 && y <= 20 && z <= 20 && x >= 0 && y >= 0 && z >= 0)
        if (f[x][y][z])
        {
            return f[x][y][z];
        }
    if ((x <= 0) || (y <= 0) || (z <= 0))
    {
        return 1;
    }
    if ((x > 20) || (y > 20) || (z > 20))
    {
        return fun(20, 20, 20);
    }
    if ((x < y) && (y < z))
    {
        return f[x][y][z] = fun(x, y, z - 1) + fun(x, y - 1, z - 1) - fun(x, y - 1, z);
    }
    return f[x][y][z] = fun(x - 1, y, z) + fun(x - 1, y - 1, z) + fun(x - 1, y, z - 1) - fun(x - 1, y - 1, z - 1);
}
void out()
{
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, fun(a, b, c));
}
int main()
{
    while (1)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if ((a == -1) && (b == -1) && (c == -1))
        {
            break;
        }
        out();
    }
    return 0;
}
