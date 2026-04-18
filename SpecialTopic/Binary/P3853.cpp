#include <iostream>
using namespace std;
const int maxn = 1000010;
long long L, N, K, l, r, ans;
int line[maxn];
bool check()
{
    long long num = 0, temp = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        if (line[i] - line[temp] > ans)
        {
            if ((line[i] - line[temp]) % ans == 0)
                num += (line[i] - line[temp]) / ans - 1;
            else
                num += (line[i] - line[temp]) / ans;
            temp = i;
        }
        else
            temp = i;
    }
    if (num <= K)
        return true;
    else
        return false;
}
int main()
{
    cin >> L >> N >> K;
    line[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> line[i];
    }
    line[N + 1] = L;
    l = 0, r = L;
    while (l < r)
    {
        ans = l + ((r - l) >> 1);
        if (check())
            r = ans;
        else
            l = ans + 1;
    }
    cout << l;
}