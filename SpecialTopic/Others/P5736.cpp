// https://www.luogu.com.cn/problem/P5736
// 质数筛
#include <iostream>
#include <vector>
const int N = 1e5 + 10;
bool num[N];
int n;
using namespace std;
void way1() // 试除法
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
                num[i] = true;
        }
    }
}
void way2() // 埃氏筛
{
    for (int i = 2; i * i <= N; i++)
    {
        if (!num[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                num[j] = true;
            }
        }
    }
}
void way3() // 欧拉筛
{
    vector<int> primes;
    for (int i = 2; i <= N; i++)
    {
        if (!num[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= N; j++)
        {
            num[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int main()
{
    num[1] = true;
    cin >> n;
    // way1();
    // way2();
    way3();
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (!num[temp])
            cout << temp << ' ';
    }
    return 0;
}