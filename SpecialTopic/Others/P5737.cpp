// https://www.luogu.com.cn/problem/P5737
// 判断闰年
// 闰年：能被4整除且不能被100整除或者能被400整除
#include <iostream>
#include <queue>
using namespace std;
bool check(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}
int main()
{
    queue<int> num;
    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++)
    {
        if (check(i))
        {
            ans++;
            num.push(i);
        }
    }
    cout << ans << '\n';
    while (!num.empty())
    {
        cout << num.front() << ' ';
        num.pop();
    }
    return 0;
}