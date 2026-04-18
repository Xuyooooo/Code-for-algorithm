// https://www.luogu.com.cn/problem/P5744
// 结构体

#include <iostream>
#include <algorithm>
using namespace std;
struct stu
{
    string name;
    int year;
    int score;
};
stu stus[6];
int progress(stu a)
{
    return min(600, (int)(a.score * 1.2));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stus[i].name >> stus[i].year >> stus[i].score;
        stus[i].score = progress(stus[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << stus[i].name << ' ' << stus[i].year + 1 << ' ' << stus[i].score << '\n';
    return 0;
}