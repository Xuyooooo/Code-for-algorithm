#include <iostream>
using namespace std;
const int N = 5e4 + 10;
int s[N], d[N]; // 0---同类，1----x吃y，2-----y吃x
int n, k, ans;

void init()
{
    // 修复 1：数组不越界，i < N
    for (int i = 0; i < N; i++)
    {
        s[i] = i;
        d[i] = 0;
    }
}

int query(int x)
{
    if (x != s[x])
    {
        int t = s[x];
        s[x] = query(s[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
    return s[x];
}

void merge(int x, int y, int relation)
{
    int rootx = query(x);
    int rooty = query(y);
    if (rootx == rooty)
    {
        if ((relation - 1) != ((d[x] - d[y] + 3) % 3))
            ans++;
    }
    else
    {
        s[rootx] = rooty;
        // 修复 2：+3 保证非负
        d[rootx] = (d[y] - d[x] + relation - 1 + 3) % 3;
    }
}

int main()
{
    cin >> n >> k;
    init();
    while (k--)
    {
        int relation, x, y;
        cin >> relation >> x >> y;
        if (x > n || y > n || (relation == 2 && x == y))
            ans++;
        else
            merge(x, y, relation);
    }
    cout << ans << '\n';
    return 0;
}