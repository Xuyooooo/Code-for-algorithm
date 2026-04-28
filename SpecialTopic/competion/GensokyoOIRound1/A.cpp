

#include <iostream>
#include <cmath>
using namespace std;
double a, b, c, l = 0, r, sum, hsum, eps;
int check(double x)
{
    double h1 = x, h2 = hsum - h1;
    double d = (a - h1) / a * (b - c) + c;
    double sum1 = (d + b) * h1 / 2 + d * h2 / 2;
    double sum2 = sum - sum1;
    double t = fabs(sum1 - sum2);
    if (t <= eps)
        return 1;
    else if (sum1 > sum2)
        return 2;
    else
        return 3;
}
int main()
{
    cin >> a >> b >> c;
    sum = (b + c) * a / 2;
    eps = sum * (1e-6);
    hsum = a / 2.0;
    r = a / 2.0;
    if (b == c)
    {
        cout << a / 2.0 << '\n';
        return 0;
    }
    else
    {
        while (l < r)
        {
            double mid = (l + r) / 2;
            int t = check(mid);
            if (t == 1)
            {
                cout << mid << '\n';
                break;
            }
            else if (t == 2)
            {
                r = mid;
            }
            else
                l = mid;
        }
    }
    return 0;
}