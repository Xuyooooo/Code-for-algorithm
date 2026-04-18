#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int wood[N];
bool check(int *a, int ans, int size, int goal)
{
    int num = 0;
    for (int i = 1; i <= size; i++)
    {
        num += a[i] / ans;
        if (num >= goal)
            return true;
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> wood[i];
    }
    sort(wood + 1, wood + n + 1);
    int l = 0, r = wood[n], ans;
    // 这里需要拿到右中位数
    while (l < r)
    {
        ans = l + ((r - l + 1) >> 1);
        if (check(wood, ans, n, k))
            l = ans;
        else
            r = ans - 1; // 左边界不能舍弃，右边界能舍弃
    }
    cout << l;
}