#include <iostream>
using namespace std;
const int maxn = 50010;
int stone[maxn];
bool check(int *stone, int n, int ans, int m)
{
    int num = 0, temp = 1, i = 1;
    while (i < n + 2)
    {
        i++;
        if (stone[i] - stone[temp] < ans)
            num++;
        else
            temp = i;
    }
    if (num > m)
        return false;
    else
        return true;
}
int main()
{
    int L, l, r, N, M, ans;
    cin >> L >> N >> M;
    stone[1] = 0;
    for (int i = 2; i <= N + 1; i++)
    {
        cin >> stone[i];
    }
    stone[N + 2] = L;
    l = 0, r = L;
    while (l < r)
    {
        ans = l + ((r - l + 1) >> 1);
        if (check(stone, N, ans, M))
            l = ans;
        else
            r = ans - 1;
    }
    cout << l;
}
// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 50001;
// int stone[MAXN], a, n, m;
// bool check(int d)
// {
//     int p = 0, ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (stone[i] - p < d)
//             ans++;
//         else
//             p = stone[i];
//     }
//     if (ans <= m)
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     scanf("%d %d %d", &a, &n, &m);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &stone[i]);
//     stone[++n] = a;
//     int l = 0, r = a, mid;
//     while (l < r)
//     {
//         mid = (l + r + 1) / 2;
//         if (check(mid))
//             l = mid;
//         else
//             r = mid - 1;
//     }
//     printf("%d\n", l);
//     return 0;
// }
