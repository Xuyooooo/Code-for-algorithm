#include <iostream>
using namespace std;
int h, m;
int main()
{
    cin >> h >> m;
    if (h < 7 || (h == 7 && m < 30))
    {
        cout << "EARLY" << '\n';
    }
    else if ((h == 7 && m >= 30) || (h == 8 && m == 0))
    {
        cout << "ON TIME" << '\n';
    }
    else
    {
        cout << "LATE" << '\n';
    }
    return 0;
}