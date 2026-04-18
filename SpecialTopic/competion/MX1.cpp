
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

// 返回不小于 n 的最小整数平方根
LL ceil_sqrt(LL n) {
    LL t = sqrt(n);
    while (t * t < n) ++t;
    while ((t - 1) * (t - 1) >= n) --t;
    return t;
}

int main() {
    int c, T;
    cin >> c >> T;
    while (T--) {
        LL n, k;
        cin >> n >> k;
        LL ans = 0;
        while (k > 0) {
            // 进入循环后的快速处理
            if (n == 1) {
                ans += k * 1;
                break;
            }
            if (n == 2) {
                ans += k * 2;
                break;
            }
            if (n == 3) {
                ans += k * 4;
                break;
            }
            // 寻找最小的可行 y
            LL y = ceil_sqrt(n);
            if ((y & 1) != (n & 1)) ++y;      // 保证奇偶一致
            LL add = (y * y - n) / 2 + 1;      // 本次操作的代价
            ans += add;
            n = y;
            --k;
        }
        cout << ans << endl;
    }
    return 0;
}