#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int line[N], n, s, t;
double l = 0, r = 0, ans;
bool check()
{
    int now = 1;
    double average = line[1];
    for (int i = 2; i <= n; i++)
    {
        if (average > ans)
            return false;
        if (line[i] > average)
            average = (line[i] - average) / (i - now + 1);
        else
        {
            average = 0;
            now = i + 1;
        }
    }
    return true;
}
int main()
{
    cin >> n >> s >> t;
    for (int i = 1; i < n; i++)
    {
        cin >> line[i];
        if (r < line[i])
            r = line[i];
    }
    while (l < r)
    {
        ans = l + ((r - l) >> 1);
    }
}