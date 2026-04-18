#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class Rank
{
public:
    int k;
    int s;
};
const int N = 5010;
Rank score[N];
int com(Rank a, Rank b)
{
    if (a.s * 10000 + 9999 - a.k > b.s * 10000 + 9999 - b.k)
        return 1;
    return 0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> score[i].k >> score[i].s;
    sort(score + 1, score + n + 1, com);
    int line = floor(m * 1.5), goal = score[line].s;
    cout << goal << ' ';
    while (score[line].s >= goal)
        line++;
    line--;
    cout << line << endl;
    for (int i = 1; i <= line; i++)
    {
        cout << score[i].k << ' ' << score[i].s << '\n';
    }
}