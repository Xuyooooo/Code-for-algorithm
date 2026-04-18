// https://www.luogu.com.cn/problem/P1019
// 搜索，DFS

#include <iostream>
#include <algorithm>
#include <string>
const int N = 21;
using namespace std;
string words[N];
int vis[N];
string ans;
int maxn = 1, n;
int check(string x, string y)
{
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int j, k, viss = 0;
        for (j = i, k = 0; j < x.size() && k < y.size(); j++, k++)
        {
            if (x[j] != y[k])
            {
                viss = 1;
                break;
            }
        }
        if (!viss && j == x.size() && k < y.size())
            return x.size() - i;
    }
    return 0;
}
void dfs()
{
    bool found = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = check(ans, words[i]);
        if (vis[i] < 2 && temp)
        {
            string backup = ans;
            ans = ans + words[i].substr(temp);
            vis[i]++;
            found = 1;
            dfs();
            ans = backup;
            vis[i]--;
        }
    }
    if (!found)
    {
        if (maxn < ans.size())
            maxn = ans.size();
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> words[i];
    }
    cin >> ans;
    dfs();
    cout << maxn << '\n';
    return 0;
}