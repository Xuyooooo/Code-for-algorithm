// https://www.luogu.com.cn/problem/P1014
// 模拟

#include <iostream>
using namespace std;
int main()
{
    int n, k = 1, i = 1, j = 1;
    cin >> n;
    bool state = 0;
    while (k < n)
    {
        if (!state)
        {
            j++;
            k++;
            while (k < n && j > 1)
            {
                i++;
                j--;
                k++;
            }
            state = 1;
        }
        else
        {
            i++;
            k++;
            while (k < n && i > 1)
            {
                i--;
                j++;
                k++;
            }
            state = 0;
        }
    }
    cout << i << '/' << j << '\n';
    return 0;
}