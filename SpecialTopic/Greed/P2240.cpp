#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 110;
class poperinity
{
public:
    int weight;
    int value;
    double danwei;
};
int compare(poperinity a, poperinity b)
{
    if (a.danwei > b.danwei)
        return 0;
    return 1;
}
poperinity treasure[N];
int main()
{
    int n, t;
    double gain = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> treasure[i].weight >> treasure[i].value;
        treasure[i].danwei = treasure[i].value * 1.0 / treasure[i].weight;
    }
    sort(treasure + 1, treasure + n + 1, compare);
    for (int i = n; i >= 0; i--)
    {
        if (t >= treasure[i].weight)
        {
            gain += treasure[i].danwei * treasure[i].weight;
            t -= treasure[i].weight;
        }
        else
        {
            gain += treasure[i].danwei * t;
            break;
        }
    }
    cout << fixed << setprecision(2) << gain;
}