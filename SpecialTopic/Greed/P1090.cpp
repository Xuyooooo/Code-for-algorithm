#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1010;
long long apple[N], temp[N];
int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    long long n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    while (q.size() > 1)
    {
        int temp1 = q.top();
        q.pop();
        int temp2 = q.top();
        q.pop();
        int temp3 = temp1 + temp2;
        q.push(temp3);
        sum += temp3;
    }
    cout << sum;
}