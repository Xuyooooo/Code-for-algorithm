#include <iostream>
#include <stack>
using namespace std;
const int N = 3e6 + 10;
int f[N], ans[N];
int main()
{
    stack<int> pos;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }
    for (int i = n; i >= 1; i--)
    {
        while (!pos.empty() && f[pos.top()] <= f[i])
            pos.pop();
        if (pos.empty())
            ans[i] = 0;
        else
            ans[i] = pos.top();
        pos.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}