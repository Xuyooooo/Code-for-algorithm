// https://www.luogu.com.cn/problem/P1103

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
int n, k;
class book
{
public:
    int h, w;
} a[N];
bool com(book a, book b)
{
    return a.h <= b.h;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].h >> a[i].w;
    sort(a + 1, a + n + 1);
}