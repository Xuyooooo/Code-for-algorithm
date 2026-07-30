#include <bits/stdc++.h>
using namespace std;
string a;
char c;
int main()
{
    cin >> c;
    getchar();
    getline(cin, a);
    int size = a.size(), num = 0;
    for (int i = 0; i < size; i++)
    {
        bool ok = 0;
        while (a[i] != ' ' && i < size)
        {
            if (a[i] == c)
            {
                ok = 1;
            }
            i++;
        }
        if (ok)
        {
            num++;
        }
    }
    cout << num << '\n';
    return 0;
}