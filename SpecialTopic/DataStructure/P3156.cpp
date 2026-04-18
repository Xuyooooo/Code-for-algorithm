// https://www.luogu.com.cn/problem/P3156
// 数组的数据结构
#include <iostream>
#include <queue>
const int N = 2000010;
int stu[N];
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> stu[i];
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        cout << stu[temp] << endl;
    }
    return 0;
}