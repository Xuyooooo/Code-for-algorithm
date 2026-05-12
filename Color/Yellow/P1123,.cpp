// https://www.luogu.com.cn/problem/P1123

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M;
int grid[10][10];
int dp[10][1 << 6];       // dp[行][当前行状态]
vector<int> legal_states; // 存储行内合法的状态（不含相邻的1）

// 判断一个状态内部是否有相邻的 1 (行内冲突)
bool check_self(int s)
{
    return !(s & (s << 1));
}

// 判断两个状态之间是否冲突 (行间冲突：正上方、左上方、右上方)
bool check_compatibility(int s1, int s2)
{
    if (s1 & s2)
        return false; // 正上方
    if (s1 & (s2 << 1))
        return false; // 左上方
    if (s1 & (s2 >> 1))
        return false; // 右上方
    return true;
}

// 计算某一行在特定状态下的数值和
int get_row_sum(int r, int s)
{
    int sum = 0;
    for (int i = 0; i < M; ++i)
    {
        if ((s >> i) & 1)
        {
            sum += grid[r][i + 1];
        }
    }
    return sum;
}

void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> grid[i][j];
        }
    }
    legal_states.clear();
    for (int s = 0; s < (1 << M); ++s)
    {
        if (check_self(s))
        {
            legal_states.push_back(s);
        }
    }

    // 2. 初始化 DP 数组
    // 因为求的是最大值，且数值非负，初始化为 -1 或 0 均可
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int s2 : legal_states)
        {
            int current_sum = get_row_sum(i, s2);

            // 枚举上一行的状态
            for (int s1 : legal_states)
            {
                // 如果上一行这个状态是可达的，并且两行不冲突
                if (dp[i - 1][s1] != -1 && check_compatibility(s1, s2))
                {
                    dp[i][s2] = max(dp[i][s2], dp[i - 1][s1] + current_sum);
                }
            }
        }
    }
    int ans = 0;
    for (int s : legal_states)
    {
        ans = max(ans, dp[N][s]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}