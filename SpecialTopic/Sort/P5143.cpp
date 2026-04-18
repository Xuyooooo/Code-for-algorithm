#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
class location
{
public:
    int x;
    int y;
    int z;
};
bool compare(location a, location b)
{
    if (a.z < b.z)
        return 1;
    return 0;
}
const int N = 50010;
location coordinate[N];
int main()
{
    int n;
    double sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> coordinate[i].x >> coordinate[i].y >> coordinate[i].z;
    }
    sort(coordinate + 1, coordinate + n + 1, compare);
    for (int i = 2; i <= n; i++)
    {
        sum += sqrt(pow(coordinate[i].x - coordinate[i - 1].x, 2) + pow(coordinate[i].y - coordinate[i - 1].y, 2) + pow(coordinate[i].z - coordinate[i - 1].z, 2));
    }
    cout << setprecision(3) << fixed << sum << endl;
    return 0;
}