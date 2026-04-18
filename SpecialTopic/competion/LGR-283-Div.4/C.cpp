

#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (a <= b)
        {
            a += temp;
            cout << 'A';
        }
        else
        {
            b += temp;
            cout << 'B';
        }
    }
    return 0;
}