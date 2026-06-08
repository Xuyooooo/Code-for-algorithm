// https://www.luogu.com.cn/problem/P1168

// 对顶堆
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, less<int>> max_heap;    // 小顶堆，只不过放的是较大的数
    priority_queue<int, vector<int>, greater<int>> min_heap; // 大顶堆，只不过放的是较小的数
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (max_heap.empty() || x <= max_heap.top())
            max_heap.push(x);
        else
            min_heap.push(x);
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (i & 1)
            cout << max_heap.top() << '\n';
    }
    return 0;
}