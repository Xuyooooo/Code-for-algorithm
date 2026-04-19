// https://www.luogu.com.cn/problem/P1008
// 模拟、枚举

#include <iostream>
using namespace std;
bool check(int m, bool *vis)
{
    int c = m % 10;
    m /= 10;
    if (vis[c] || !c)
        return false;
    vis[c] = 1;
    int b = m % 10;
    m /= 10;
    if (vis[b] || !b)
        return false;
    vis[b] = 1;
    int a = m % 10;
    if (vis[a] || !a)
        return false;
    vis[a] = 1;
    return true;
}
int main()
{
    for (int i = 103; i < 333; i++) // 最小的数的范围
    {
        bool vis[10] = {false};
        if (check(i, vis) && check(2 * i, vis) && check(3 * i, vis))
            cout << i << ' ' << 2 * i << ' ' << 3 * i << '\n';
    }
    return 0;
}