// https://www.luogu.com.cn/problem/P1886
//  洛谷P1886单调队列/滑动窗口
//  单调队列可以优化的问题具有以下特点
//  在一个区间[l,r]上求最值
//  区间左右端点l,r均单调不减/单调不增
#include <iostream>
#include <deque>
using namespace std;
const int N = 1000005;
int a[N];
deque<int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 处理最小值
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= m)
        {
            while (!q.empty() && q.front() <= i - m)
                q.pop_front();
            cout << a[q.front()] << ' ';
        }
    }
    // 处理最大值
    cout << endl;
    while (!q.empty())
        q.pop_front();
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= m)
        {
            while (!q.empty() && q.front() <= i - m)
                q.pop_front();
            cout << a[q.front()] << ' ';
        }
    }
    cout << endl;
    return 0;
}