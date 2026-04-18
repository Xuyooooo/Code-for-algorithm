#include <iostream>
using namespace std;
int hashh[15010];
int main()
{
    int n, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        hashh[temp]++;
    }
    for (int i = 1; i <= 5010; i++)
    {
        if (hashh[i] >= 2 && hashh[2 * i] >= 2)
        {
            num += hashh[i] * (hashh[i] - 1) * hashh[2 * i] * (hashh[2 * i] - 1) / 4;
        }
    }
    cout << num % 1000000007;
}