#include <iostream>
#include <string>
using namespace std;
int n;
string a, b, c;
int qianqu1[10010];
int qianqu2[10010];
int output[10010];
int main()
{
    int T, now;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        now = 1;
        cin >> n >> a >> b >> c;
        for (int i = 0; i <= n - 1; i++)
        {
            if (a[i] == 1)
            {
                for (int j = now; j <= i; j++)
                {
                    qianqu1[j] = i + 1;
                }
                now = i;
            }
        }
        now = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 1)
            {
                for (int j = now; j > i + 1; j--)
                {
                    qianqu2[j] = i + 1;
                }
                now = i;
            }
        }
    }
    for (int i = 1; qianqu1[i] != 0; i++)
    {
    }
}