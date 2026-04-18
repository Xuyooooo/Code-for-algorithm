#include <iostream>
#include <iomanip>
using namespace std;
bool check(int w0, int w, int m, int ans)
{
    //     while()
    //     {

    //     }
}
int main()
{
    int w0, w, m;
    cin >> w0 >> w >> m;
    double l = 0, r = 3, ans;
    while (r - l > 0.1)
    {
        ans = l + (r - l) / 2;
        if (check(w0, w, m, ans))
            l = ans;
        else
            r = ans - 0.1;
    }
    cout << l;
}