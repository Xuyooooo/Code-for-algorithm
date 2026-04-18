#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class s
{
public:
    int location;
    int state = 1;
    char num;
};
bool com1(s a, s b)
{
    if (a.num <= b.num)
        return 1;
    return 0;
}
bool com2(s a, s b)
{
    return a.location < b.location;
}
int main()
{
    s ss[251];
    int k;
    string before, after;
    cin >> before >> k;
    for (int i = 0; i < before.size(); i++)
    {
        ss[i].location = i;
        ss[i].num = before[i];
    }
    sort(ss, ss + before.size(), com1);
    sort(ss, ss + before.size() - k, com2);
    for (int i = 0; i < before.size() - k; i++)
        cout << before[ss[i].location];
}