// 洛谷P5019https://www.luogu.com.cn/problem/P5019
#include <iostream>
const int N = 100010;
using namespace std;
int line[N];
int main()
{
    int n, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> line[i];
    }
    // 先从第一位，若第一位大于0则从此位置开始向后每一位若大于0则减一直至遇到0再num++
    // 然后继续进行直到第一位为0
    // 这样子保证了填坑的最大化
    for (int i = 1; i <= n; i++)
    {
        while (line[i])
        {
            int j = i;
            while (line[j] > 0 && j <= n)
            {
                line[j]--;
                j++;
            }
            num++;
        }
    }
    cout << num;
}