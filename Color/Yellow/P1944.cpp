// https://www.luogu.com.cn/problem/P1944

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool state = 0;
    stack<char> a;
    string ans, res;
    char d;
    scanf("%c", &d);
    while (d != '\n')
    {
        if (state)
        {
            if (!a.empty() && ((a.top() == '(' && d == ')') || (a.top() == '[' && d == ']')))
            {
                ans = ans + d;
                ans = a.top() + ans;
                a.pop();
            }
            else
            {
                state = 0;
                a.push(d);
                if (ans.size() > res.size())
                {
                    res = ans;
                    ans.clear();
                }
            }
        }
        else
        {
            if (!a.empty() && ((a.top() == '(' && d == ')') || (a.top() == '[' && d == ']')))
            {
                state = 1;
                ans = ans + d;
                ans = a.top() + ans;
                a.pop();
            }
            else
            {
                a.push(d);
            }
        }
        scanf("%c", &d);
    }
    cout << res << '\n';
    return 0;
}
