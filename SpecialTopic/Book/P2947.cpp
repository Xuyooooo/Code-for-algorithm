#include <iostream>
#include <stack>
using namespace std;
const int N = 100010;
int cow[N], ans[N];
stack<int> pos;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    for (int i = n; i >= 1; i--)
    {
        while (!pos.empty() && cow[pos.top()] <= cow[i])
            pos.pop();
        if (pos.empty())
            ans[i] = 0;
        else
            ans[i] = pos.top();
        pos.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}