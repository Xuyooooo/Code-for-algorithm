#include <iostream>
const int N = 5e5 + 10;
long long ans = 0, n;
int num[N];
void merge(int a, int b, int c);
using namespace std;
void sorrt(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    sorrt(l, mid);
    sorrt(mid + 1, r);
    merge(l, mid, r);
}
void merge(int l, int mid, int r)
{
    int *temp = new int[r - l + 1];
    int p1 = l, p2 = mid + 1, i = 0;
    while (p1 <= mid && p2 <= r)
    {
        if (num[p1] <= num[p2])
        {
            temp[i++] = num[p1++];
        }
        else
        {
            temp[i++] = num[p2++];
            ans += mid - p1 + 1; // 只有选择右边时才加
        }
    }
    while (p1 <= mid)
    {
        temp[i++] = num[p1++];
    }
    while (p2 <= r)
    {
        temp[i++] = num[p2++];
    }
    for (int j = 0; j <= r - l; j++)
        num[l + j] = temp[j];
    delete[] temp;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    sorrt(1, n);
    cout << ans;
    return 0;
}