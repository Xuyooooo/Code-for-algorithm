#include <iostream>
using namespace std;
const int maxn = 100010;
int n, p, l, r, ans;
class device
{
public:
    int a;
    int b;
    double time;
};
device de[maxn];
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> de[i].a >> de[i].b;
        de[i].time = de[i].a * 1.0 / de[i].b;
    }
}