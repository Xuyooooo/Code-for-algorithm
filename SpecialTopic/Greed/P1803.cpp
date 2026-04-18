#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;
class competition
{
public:
    int start;
    int end;
};
competition act[N];
int compare(competition a, competition b)
{
    if (a.end < b.end)
        return 1;
    if (a.end == b.end && a.end - a.start <= b.end - b.start)
        return 1;
    return 0;
}
int main()
{
    int n, num = 1, start, end;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> act[i].start >> act[i].end;
    }
    sort(act + 1, act + n + 1, compare);
    end = act[1].end;
    for (int i = 2; i <= n; i++)
    {
        if (act[i].start < end)
            continue;
        else
        {
            end = act[i].end;
            num++;
        }
    }
    cout << num;
}