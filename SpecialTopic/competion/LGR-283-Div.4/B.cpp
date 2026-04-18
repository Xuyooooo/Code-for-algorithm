

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a >= 8 && b <= 12 && b >= a)
        cout << 'M' << '\n';
    else if (a >= 13 && b <= 17 && b >= a)
        cout << 'A' << '\n';
    else if (a >= 18 && b <= 21 && b >= a)
        cout << 'E' << '\n';
    else
        cout << 'F' << '\n';
    return 0;
}