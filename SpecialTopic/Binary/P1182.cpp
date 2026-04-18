#include <iostream>
using namespace std;
const int N = 100001;
int input[N];
bool check(int n, long long ans, int m)
{
    int num = 1; // 提前把最后位置的分组加上去
    long long temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (temp + input[i] <= ans)
        {
            temp += input[i];
        }
        else
        {
            if (i != n - 1) // 这里需要考虑最后一次的特殊情况，以防多加1
                num++;
            temp = input[i];
        }
    }
    return num <= m;
}
int main()
{
    int n, m;
    long long l = 0, r = 0, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
        if (l < input[i])
            l = input[i];
        r += input[i];
    }
    while (l < r)
    {
        ans = l + ((r - l) >> 1);
        if (check(n, ans, m))
            r = ans; // 检查true，说明ans偏大让分组偏小，则右边界改变，但不能减1，因为此时可能处于最小值
        else
            l = ans + 1;
    }
    cout << l;
    return 0;
}