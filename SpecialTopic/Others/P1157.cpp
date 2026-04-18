// https://www.luogu.com.cn/problem/P1157
// 深搜
// 排列

#include <iostream>
#include <iomanip>
const int N = 21;
int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
bool iff[N];
int ans[N];
int n, r;
using namespace std;
void dfs(int i, int cur)
{
    // 注意这里应该先判断是否输出再判断是否越界
    if (cur > r)
    {
        for (int j = 1; j <= r; j++)
            cout << setw(3) << ans[j];
        cout << '\n';
        return;
    }
    if (i > n)
        return;

    for (int j = i; j <= n; j++)
    {
        if (!iff[j])
        {
            ans[cur] = a[j];
            iff[j] = true;
            dfs(j + 1, cur + 1);
            iff[j] = false;
        }
    }
}
int main()
{
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}