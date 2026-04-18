#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 110;
class classmates
{
public:
    string name;
    int id;
    int year;
    int month;
    int day;
};
int compare(classmates a, classmates b)
{
    if (a.year < b.year)
        return 1;
    if (a.year == b.year && a.month < b.month)
        return 1;
    if (a.year == b.year && a.month == b.month && a.day < b.day)
        return 1;
    if (a.year == b.year && a.month == b.month && a.day == b.day && a.id > b.id)
        return 1;
    return 0;
}
classmates stu[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stu[i].id = i;
        cin >> stu[i].name >> stu[i].year >> stu[i].month >> stu[i].day;
    }
    sort(stu + 1, stu + n + 1, compare);
    for (int i = 1; i <= n; i++)
    {
        cout << stu[i].name << endl;
    }
}
// 重载写法
//  #include <iostream>
//  #include <algorithm>
//  using namespace std;
//  struct student
//  {
//      string id;
//      int y, m, d, f; // 年，月，日，输入序号。
//      bool operator<(student &u) //重载小于号<,实现自定义排序，要放在结构体里面
//      { // 重载运算符。
//          if (u.y == y)
//          {
//              if (u.m == m)
//              {
//                  if (u.d == d)
//                      return u.f < f;
//                  else
//                      return u.d > d;
//              }
//              else
//                  return u.m > m;
//          }
//          else
//              return u.y > y;
//      }
//  } a[128];
//  int main()
//  {
//      int n;
//      cin >> n;
//      for (int i = 1; i <= n; i++)
//      {
//          cin >> a[i].id >> a[i].y >> a[i].m >> a[i].d;
//          a[i].f = i; // 后输入的先输出
//      }
//      sort(a + 1, a + 1 + n); // 直接排序
//      for (int i = 1; i <= n; i++)
//          cout << a[i].id << '\n';
//      return 0;
//  }
