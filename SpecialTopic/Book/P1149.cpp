#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int temp = 0;
    string input;
    stack<int> num;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            temp *= 10;
            temp += input[i] - '0';
        }
        else if (input[i] == '.')
        {
            num.push(temp);
            temp = 0;
        }
        else if (input[i] == '+')
        {
            int temp1 = num.top();
            num.pop();
            int temp2 = num.top();
            num.pop();
            num.push(temp2 + temp1);
        }
        else if (input[i] == '-')
        {
            int temp1 = num.top();
            num.pop();
            int temp2 = num.top();
            num.pop();
            num.push(temp2 - temp1);
        }
        else if (input[i] == '*')
        {
            int temp1 = num.top();
            num.pop();
            int temp2 = num.top();
            num.pop();
            num.push(temp2 * temp1);
        }
        else if (input[i] == '/')
        {
            int temp1 = num.top();
            num.pop();
            int temp2 = num.top();
            num.pop();
            num.push(temp2 / temp1);
        }
        else if (input[i] == '@')
            break;
    }
    cout << num.top() << endl;
    return 0;
}