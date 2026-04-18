#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
int n, s, a, b;
class app
{
public:
    int x;
    int y;
};
app apples[N];
bool com(app a1, app b1)
{
    if (a1.x <= a + b && b1.x > a + b)
        return true;
    else if (a1.x <= a + b && b1.x <= a + b && a1.y <= b1.y)
        return true;
    return false;
}
int main()
{
    int num = 0;
    cin >> n >> s >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> apples[i].x >> apples[i].y;
    sort(apples + 1, apples + n + 1, com);
    for (int i = 1; i <= n; i++)
    {
        if (s >= apples[i].y)
        {
            num++;
            s -= apples[i].y;
        }
        else
            break;
    }
    cout << num;
}