// https://www.luogu.com.cn/problem/P3150

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n & 1)
            cout << "zs wins" << '\n';
        else
            cout << "pb wins" << '\n';
    }
    return 0;
}