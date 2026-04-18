#include <iostream>
using namespace std;
const int N = 21;
int a[N], b[N], c[N], d[N];
int s1, s2, s3, s4, l = 0, r = 1e4, ans;
bool check()
{
}
int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    return 0;
    for (int i = 1; i <= s1; i++)
        cin >> a[i];
    for (int i = 1; i <= s2; i++)
        cin >> b[i];
    for (int i = 1; i <= s3; i++)
        cin >> c[i];
    for (int i = 1; i <= s4; i++)
        cin >> d[i];
    while (l < r)
    {
        ans = l + ((r - l) >> 1);
        if (check())
            r = ans;
        else
            l = ans + 1;
    }
}