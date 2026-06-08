// https://www.luogu.com.cn/problem/P1165
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    stack<int> stk;
    stack<int> max_stk;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int x;
            cin >> x;
            stk.push(x);
            if (max_stk.empty())
            {
                max_stk.push(x);
            }
            else
            {
                max_stk.push(max(x, max_stk.top()));
            }
        }
        else if (op == 1)
        {
            if (!stk.empty())
            {
                stk.pop();
                max_stk.pop();
            }
        }
        else if (op == 2)
        {
            if (max_stk.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << max_stk.top() << "\n";
            }
        }
    }
    return 0;
}