#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a = min(i - 1, n - i);
            int b = min(j - 1, n - j);
            if ((min(a, b) + 1) & 1)
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}