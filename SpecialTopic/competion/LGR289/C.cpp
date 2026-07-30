#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, v, a;
    cin >> n >> v;
    while (n--)
    {
        cin >> a;
        if (a)
        {
            v = min(10, v + 1);
        }
        else
        {
            v = max(0, v - 1);
        }
    }
    cout << v << '\n';
    return 0;
}