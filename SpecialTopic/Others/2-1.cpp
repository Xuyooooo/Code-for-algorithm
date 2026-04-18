#include <iostream>
using namespace std;
int main()
{
    int ans = 0, i = 1;
    do
    {
        ans += i++;
    } while (i <= 10);
    cout << ans << '\n';
    return 0;
}