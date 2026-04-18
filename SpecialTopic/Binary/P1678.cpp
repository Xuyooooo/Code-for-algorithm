#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int school[N];
int student[N];
int main()
{
    long long m, n, sum = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> school[i];
    for (int i = 1; i <= n; i++)
        cin >> student[i];
    sort(school + 1, school + m + 1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(school + 1, school + m + 1, student[i]) - school;
        if (pos == m + 1)
            sum += student[i] - school[pos - 1];
        else
        {
            if (pos == 1)
                sum += school[pos] - student[i];
            else
                sum += min(school[pos] - student[i], student[i] - school[pos - 1]);
        }
    }
    cout << sum;
    return 0;
}