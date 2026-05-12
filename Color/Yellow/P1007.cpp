// https://www.luogu.com.cn/problem/P1007

// 这题其实是靠思维的
// 可以这样子理解：两个人相遇时他们都会掉头，这可以看成继续沿着当前道路走，即碰撞等于相互穿过，每个人都在独立地走自己的路，互不干扰
// 那么只需要计算出每个人撤离的最短和最长时间，然后去极值
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int L, n;
    cin >> L >> n;
    if (n == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    int min_ans = 0;
    int max_ans = 0;
    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;
        int to_near = min(pos, L - pos + 1);
        int to_far = max(pos, L - pos + 1);
        min_ans = max(min_ans, to_near);
        max_ans = max(max_ans, to_far);
    }
    cout << min_ans << " " << max_ans << endl;
    return 0;
}