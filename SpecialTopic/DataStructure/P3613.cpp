// https://www.luogu.com.cn/problem/P3613
// map+vector
#include <iostream>
const int N = 100010;
int save[N][N];
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            int j, k, l;
            cin >> j >> k >> l;
            save[j][k] = l;
        }
        else
        {
            int j, k;
            cin >> j >> k;
            cout << save[j][k] << endl;
        }
    }
    return 0;
}