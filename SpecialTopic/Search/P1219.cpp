// https://www.luogu.com.cn/problem/P1219
// 搜索(深搜)

//===============本人===========
// #include <iostream>
// using namespace std;
// const int N = 14;
// bool a[N][N];
// int ans[N], n, num = 0;
// bool check(int row, int colume)
// {
//     for (int i = row - 1, j = colume - 1; j >= 1 && i >= 1; i--, j--)
//     {
//         if (a[i][j])
//             return false;
//     }
//     for (int i = row - 1, j = colume + 1; i >= 1 && j <= n; i--, j++)
//     {
//         if (a[i][j])
//             return false;
//     }
//     for (int i = row - 1; i >= 1; i--)
//     {
//         if (a[i][colume])
//             return false;
//     }
//     return true;
// }
// void dfs(int row, int colume, int cur)
// {
//     if (cur == n)
//     {
//         num++;
//         if (num <= 3)
//         {
//             for (int i = 1; i <= n; i++)
//                 cout << ans[i] << ' ';
//             cout << '\n';
//         }
//         return;
//     }
//     for (int i = row + 1, j = 1; i <= n, j <= n; j++)
//     {
//         if (check(i, j))
//         {
//             a[i][j] = 1;
//             ans[cur + 1] = j;
//             dfs(i, j, cur + 1);
//             a[i][j] = 0;
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1, j = 1; j <= n; j++)
//     {
//         ans[i] = j;
//         a[i][j] = 1;
//         dfs(i, j, 1);
//         a[i][j] = 0;
//     }
//     cout << num << '\n';
//     return 0;
// }

//==============豆包-压缩空间====================
#include <iostream>
using namespace std;
const int N = 14;
bool col[N];       // 列是否占用
bool diag1[N * 2]; // 主对角线
bool diag2[N * 2]; // 副对角线 /
int ans[N];
int n, total = 0;

void dfs(int row)
{
    if (row > n)
    {
        total++;
        if (total <= 3)
        {
            for (int i = 1; i <= n; ++i)
                cout << ans[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int c = 1; c <= n; ++c)
    {
        if (!col[c] && !diag1[row + c] && !diag2[row - c + n])
        {
            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + n] = true;
            ans[row] = c;
            dfs(row + 1);
            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + n] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << total << endl;
    return 0;
}