// https://www.luogu.com.cn/problem/P1017

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int n, base;
int main()
{
    stack<int> output;
    int sum = 0, i = 0;
    cin >> n >> base;
    while (sum != n)
    {
        int t = n & 1;
        output.push(t);
        if (t)
            sum += t * pow(base, i);
        i++;
        n >> 1;
    }
    while (!output.empty())
    {
        cout << output.top();
    }
    cout << "base" << base << '\n';
    return 0;
}