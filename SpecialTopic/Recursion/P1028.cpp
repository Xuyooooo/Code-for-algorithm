#include <iostream>
using namespace std;
int main()
{
    int ans[100010];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            ans[i] += ans[j];
        }
    }
    cout << ans[n];
    return 0;
}