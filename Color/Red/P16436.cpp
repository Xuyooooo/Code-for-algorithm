// https://www.luogu.com.cn/problem/P16436

#include <iostream>
using namespace std;
int main()
{
    int ans = 0, a;
    for (int i = 1; i <= 6; i++)
    {
        cin >> a;
        ans += a;
    }
    if (ans == 3)
    {
        cout << "Congratulations on graduation!" << '\n';
    }
    else
        cout << "Songfes in Japan..." << '\n';
    return 0;
}