#include <iostream>
#define endl '\n'
using namespace std;
int n;
void solve(int x)
{
    int ans = 0, temp1 = 1, temp2 = 2, temp3 = x;
    while (temp3)
    {
        if (temp3 & 1)
        {
            temp1 *= temp2;
        }
        if (temp3 != x)
            ans++;
        temp3 >>= 1;
        temp2 *= temp2;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n)
    {
        solve(n);
        cin >> n;
    }
    return 0;
}