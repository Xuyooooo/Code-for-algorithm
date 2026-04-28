// https://www.luogu.com.cn/problem/P1036

#include <iostream>
using namespace std;
const int N = 21;
int num[N], n, m, ans;
bool num1[N];
// bool primes[]
void check(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return;
    }
    ans++;
}
void dfs(int now, int sum)
{
    if (now == m + 1)
    {
        cout << sum << '\n';
        check(sum);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num1[i])
        {
            num1[i] = 1;
            dfs(now + 1, sum + num[i]);
            num[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}