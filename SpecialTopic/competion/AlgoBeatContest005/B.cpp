// https://www.luogu.com.cn/problem/P16430?contestId=316306

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1001;
long long n, k;
class a
{
public:
    long long p;
    long long w;
} in[N];
long long sd[N];
long long ans;
bool com(a b, a c)
{
    if (b.p <= c.p)
        return true;
    return false;
}
int main()
{
    ans = 1e18;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> in[i].p;
    for (int i = 1; i <= n; i++)
        cin >> in[i].w;
    if (k == 1)
        ans = 0;
    else
    {
        sort(in + 1, in + n + 1, com);
        for (int i = k; i <= n; i++)
        {
            long long temp = 0;
            int p = 1;
            for (int j = 1; j <= i - 1; j++)
            {
                sd[p++] = (in[i].p - in[j].p) * in[j].w;
            }
            sort(sd + 1, sd + p); // 这里其实可以用大根堆来存储的，可以避免再一次sort
            for (int h = 1; h <= k - 1; h++)
                temp += sd[h];
            ans = min(ans, temp);
        }
    }
    cout << ans << '\n';
    return 0;
}
