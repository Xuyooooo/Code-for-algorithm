// https://www.luogu.com.cn/problem/P1506

// 先统计外层的0，并改变相应位置的状态
// 然后再统计个数
#include <iostream>
#include <string>
using namespace std;
const int N = 505;
string in[N];
bool vis[N][N];
int x, y;
void dfs(int r, int c)
{
    if (r < 1 || r > x || c < 0 || c >= y || in[r][c] == '*' || vis[r][c])
    {
        return;
    }
    vis[r][c] = true;
    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> x >> y;
    for (int i = 1; i <= x; i++)
    {
        cin >> in[i];
    }
    for (int i = 1; i <= x; i++)
    {
        dfs(i, 0);
        dfs(i, y - 1);
    }
    for (int j = 0; j < y; j++)
    {
        dfs(1, j);
        dfs(x, j);
    }
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (in[i][j] == '0' && !vis[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}