#include <iostream>
using namespace std;
int a, b, p, q, m;
int main()
{
    cin >> a >> b >> p >> q >> m;
    cout << a * p + b * q << '\n';
    cout << m - a * p - b * q << '\n';
    return 0;
}