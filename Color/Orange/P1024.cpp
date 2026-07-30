// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e3 + 10;
// int n;
// class cl
// {
// public:
//     int l;
//     int r;
// } line[N];
// bool com(cl a, cl b)
// {
//     return a.l <= b.l;
// }
// void solve()
// {
//     int ans1 = 0, ans2 = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> line[i].l >> line[i].r;
//     }
//     sort(line + 1, line + n + 1, com);
//     int now = 1;
//     int orig = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         if (line[i].l <= line[now].r)
//         {
//             now = line[i].r > line[now].r ? i : now;
//         }
//         else
//         {
//             ans1 = max(ans1, line[now].r - line[orig].l);
//             ans2 = max(ans2, line[i].l - line[now].r);
//             now = orig = i;
//         }
//     }
//     ans1 = max(ans1, line[now].r - line[orig].l);
//     cout << ans1 << ' ' << ans2 << '\n';
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, l, r, a[N];
void solve()
{
    int L = 1e9;
    int R = 0;
    int ans1 = 0;
    int ans2 = 0;
    int sum = 0;
    int len1 = 0;
    int len2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        a[l]++;
        a[r]--;
        L = min(L, l);
        R = max(R, r);
    }
    for (int i = L; i < R; i++)
    {
        sum += a[i];
        if (sum > 0)
        {
            len1++;
            len2 = 0;
            ans1 = max(ans1, len1);
        }
        else
        {
            len2++;
            len1 = 0;
            ans2 = max(ans2, len2);
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}