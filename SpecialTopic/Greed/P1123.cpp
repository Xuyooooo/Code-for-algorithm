#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 1010;
class line
{
public:
    int time;
    int num;
};
line person[N];
int waittime[N];
int compare(line a, line b)
{
    if (a.time < b.time)
        return 1;
    return 0;
}
int main()
{
    double sum = 0;
    int n;
    cin >> n;
    waittime[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        person[i].num = i;
        cin >> person[i].time;
    }
    sort(person + 1, person + n + 1, compare);
    cout << person[1].num << ' ';
    for (int i = 2; i <= n; i++)
    {
        cout << person[i].num << ' ';
        waittime[i] = waittime[i - 1] + person[i - 1].time;
        sum += waittime[i];
    }
    cout << endl
         << fixed << setprecision(2) << sum * 1.0 / n;
}