// https://www.luogu.com.cn/problem/P2676
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, goal, sum = 0;
    cin >> n >> goal;
    int *cow = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    sort(cow, cow + n);
    for (int i = n - 1; i >= 0; i--)
    {
        sum += cow[i];
        if (sum >= goal)
        {
            cout << n - i;
            break;
        }
    }
    delete[] cow;
    return 0;
}