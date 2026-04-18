#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;
int a[N];
void Binary_Search(int *a, int goal, int start, int end)
{
    int id = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (a[mid] == goal)
        {
            end = mid - 1;
            id = mid;
        }
        else if (a[mid] < goal)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << id << ' ';
}
// stl里面的upper_bound()函数，返回的是第一个大于目标数的地址
// 也可以用stl里面的lower_bound()函数,返回的是数组中第一个大于等于目标数的地址
void stl(int *a, int n, int goal)
{
    int ans = lower_bound(a + 1, a + n + 1, goal) - a; // 这里不i需要除以4，因为系统已经帮除4了，返回的就是下标之差而不是字节差
    if (goal != a[ans])
        cout << -1;
    else
        cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int goal;
        cin >> goal;
        Binary_Search(a, goal, 1, n);
    }
    return 0;
}