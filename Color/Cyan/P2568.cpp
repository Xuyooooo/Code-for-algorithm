#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

const int N = 1e7 + 5;
int n;

vector<int> primes; // 存储筛出的质数
bool is_prime[N];   // 标记是否为质数
int phi[N];         // 欧拉函数
ll sum_phi[N];      // 欧拉函数的前缀和

// 1. 线性筛：O(N) 预处理质数、欧拉函数及其前缀和
void init(int max_n)
{
    fill(is_prime, is_prime + max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    phi[1] = 1;

    for (int i = 2; i <= max_n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            phi[i] = i - 1; // 质数的 phi(p) = p - 1
        }
        for (int p : primes)
        {
            if (i * p > max_n)
                break;
            is_prime[i * p] = false;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p; // p 是 i 的因子
                break;
            }
            else
            {
                phi[i * p] = phi[i] * (p - 1); // p 不是 i 的因子
            }
        }
    }

    // 计算欧拉函数前缀和
    for (int i = 1; i <= max_n; i++)
    {
        sum_phi[i] = sum_phi[i - 1] + phi[i];
    }
}

void solve()
{
    if (!(cin >> n))
        return;

    // 预处理 1~n 的信息
    init(n);

    ll ans = 0;

    // 2. 枚举每一个质数 p
    for (int p : primes)
    {
        int m = n / p;
        // O(1) 加上 [1, m] 范围内互质数对的总数
        ans += 2 * sum_phi[m] - 1;
    }

    cout << ans << endl;
}

int main()
{
    // I/O 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}