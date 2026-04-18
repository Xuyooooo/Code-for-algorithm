#include <iostream>
using namespace std;
const int N = 100010;
int candy[N];
long long n, x;
int main()
{
    long long sum = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> candy[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (candy[i] + candy[i - 1] > x)
        {
            int temp = candy[i] + candy[i - 1];
            sum += candy[i] + candy[i - 1] - x;
            if (candy[i] >= 0)
            {
                if (candy[i] >= temp - x)
                    candy[i] -= temp - x;
                else
                {
                    candy[i - 1] -= temp - x - candy[i];
                    candy[i] = 0;
                }
            }
            candy[i] -= candy[i] + candy[i - 1] - x;
        }
    }
    cout << sum;
}