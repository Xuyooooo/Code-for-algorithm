// https://www.luogu.com.cn/problem/P1440

//==============单调队列、滑动窗口变形===============
#include <iostream>
#include <deque>
using namespace std;
const int N = 2e6 + 10;
int input[N];
int n, m;
int main()
{
    deque<int> a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    int i = 2;
    cout << 0 << '\n';
    a.push_back(1);
    while (i <= n)
    {
        while (i - a.front() > m && !a.empty())
            a.pop_front();
        cout << input[a.front()] << '\n';
        while (!a.empty() && input[a.back()] > input[i])
            a.pop_back();
        a.push_back(i);

        i++;
    }
    return 0;
}