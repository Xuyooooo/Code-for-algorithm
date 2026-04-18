#include <iostream>
using namespace std;
long long location[30][30];
int main()
{
    location[0][0] = 1;
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    location[y][z] = -1;
    if (y - 2 >= 0 && z - 1 >= 0)
        location[y - 2][z - 1] = -1;
    if (y - 2 >= 0)
        location[y - 2][z + 1] = -1;
    if (y - 1 >= 0 && z - 2 >= 0)
        location[y - 1][z - 2] = -1;
    if (y - 1 >= 0)
        location[y - 1][z + 2] = -1;
    if (z - 1 >= 0)
        location[y + 2][z - 1] = -1;
    location[y + 2][z + 1] = -1;
    location[y + 1][z + 2] = -1;
    if (z - 2 >= 0)
        location[y + 1][z - 2] = -1;
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (location[i][j] < 0)
                continue;
            if (location[i - 1][j] >= 0 && i - 1 >= 0)
                location[i][j] += location[i - 1][j];
            if (location[i][j - 1] >= 0 && j - 1 >= 0)
                location[i][j] += location[i][j - 1];
        }
    }
    cout << location[w][x];
}