// https://www.luogu.com.cn/problem/P3613

// map数组
#include <iostream>
// #include <vector>
#include <map>
using namespace std;
// map是一个映射容器，只有存入数据的时候，它才会消耗内存
map<int, int> locker[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            if (k == 0)
            {
                locker[i].erase(j);
            }
            else
            {
                locker[i][j] = k;
            }
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << locker[i][j] << "\n";
        }
    }
    return 0;
}