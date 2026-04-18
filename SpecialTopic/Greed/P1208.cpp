// https://www.luogu.com.cn/problem/P1208
// 贪心策略
// 自定义比较函数
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3 + 10;
class aa
{
public:
    int price;
    int story;
};
aa cow[N];
int n, m;
long long ans = 0;
bool com(aa a, aa b)
{
    if (a.price < b.price) // 此处里不能用<=，比较函数里面只能用<
        return true;
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> cow[i].price >> cow[i].story;
    }
    sort(cow + 1, cow + m + 1, com);
    for (int i = 1; i <= m; i++)
    {
        ans += cow[i].price * min(n, cow[i].story);
        n -= cow[i].story;
        if (n <= 0)
            break;
    }
    cout << ans << '\n';
    return 0;
}