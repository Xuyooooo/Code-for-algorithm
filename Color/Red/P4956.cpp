// https://www.luogu.com.cn/problem/P4956

#include <iostream>
using namespace std;
int main()
{
    int N, X, K;
    cin >> N;
    for (X = 100; X > 0; X--)
    {
        for (K = 1;; K++)
        {

            if (52 * (7 * X + 21 * K) > N)
            {
                break;
            }
        }
    }
    std::cout << X << std::endl
              << K;
}