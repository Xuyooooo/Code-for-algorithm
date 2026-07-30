// https://www.luogu.com.cn/problem/P1918
#include <iostream>
#include <map>
using namespace std;
int a, n, q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        ans[a] = i;
    }
    cin >> q;
    while (q--)
    {
        cin >> a;
        cout << ans[a] << endl;
    }
    return 0;
}