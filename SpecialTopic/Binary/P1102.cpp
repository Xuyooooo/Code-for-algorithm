#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
long long haash[1000010];
long long input[N];
// 可以采用双指针
void two_points(long long *a, long long n, long long c)
{
    long long p1 = 1, p2 = 1;
    long long ans = 0;
    sort(a + 1, a + n + 1);
    for (long i = 1; i <= n; i++)
    {
        while (p1 <= n && a[p1] - a[i] <= c)
            p1++;
        while (p2 <= n && a[p2] - a[i] < c)
            p2++;
        if (a[p2] - a[i] == c && a[p1 - 1] - a[i] == c && p1 - p2 >= 1)
            ans += p1 - p2;
    }
    cout << ans;
}
// 可以用哈希表记录一个数出现次数，但范围小了，只能得92
int main()
{
    long long n, c, num = 0;
    cin >> n >> c;
    for (long long i = 1; i <= n; i++)
    {
        cin >> input[i];
        // haash[input[i]]++;
    }
    // for (long long i = 1; i <= n; i++)
    // {
    //     if (input[i] - c >= 0 && haash[input[i] - c] > 0)
    //     {
    //         num += haash[input[i] - c];
    //     }
    // }
    // cout << num;
    two_points(input, n, c);
}