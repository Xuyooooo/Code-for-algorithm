#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<char> bracket;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '@')
            break;
        if (input[i] == '(')
            bracket.push(input[i]);
        if (input[i] == ')')
        {
            if (bracket.empty())
            {
                cout << "NO";
                return 0;
            }
            else
            {
                if (bracket.top() != '(')
                {
                    cout << "NO";
                    break;
                }
                else
                {
                    bracket.pop();
                }
            }
        }
    }
    if (bracket.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}