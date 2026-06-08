#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    int n, a, b, opt, c;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> opt >> c;
        if (opt == 1)
        {
            if (c >= a)
                cout << 'Y';
            else
                cout << 'N';
        }
        else
        {
            if (c >= b)
                cout << 'Y';
            else
                cout << 'N';
        }
    }
    return 0;
}