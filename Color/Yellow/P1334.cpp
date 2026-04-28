// https://www.luogu.com.cn/problem/P1334
// 大根堆，贪心

#include <iostream>
#include <queue>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    int temp, sum = 0;
    priority_queue<int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum += temp;
        a.push(temp);
    }
    while (a.size() >= 2)
    {
        ans += sum;
        sum -= a.top();
        a.pop();
    }
    cout << ans << '\n';
    return 0;
}