#include <iostream>
const int N = 130;
int input[N][N];
int sum[N][N];
int n;
using namespace std;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> input[i][j];
            sum[i][j] = sum[i][j - 1];
            for (int i = 1; i < j; i++)
                sum[i][j] += sum[i - 1][j];
            sum[i][j] += input[i][j];
        }
    }
    return 0;
}