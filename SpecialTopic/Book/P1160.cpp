// #include <iostream>
// #include <list>
// using namespace std;
// int haash[1000010];
// int main()
// {
//     list<int> line;
//     int N, M;
//     cin >> N;
//     line.push_back(1);
//     for (int i = 2; i <= N; i++)
//     {
//         int k, p;
//         cin >> k >> p;
//         for (auto it = line.begin(); it != line.end(); it++)
//         {
//             if (*it == k)
//             {
//                 if (p)
//                     line.insert(++it, i);
//                 else
//                     line.insert(it, i);
//                 break;
//             }
//         }
//     }
//     cin >> M;
//     for (int i = 1; i <= M; i++)
//     {
//         int x;
//         cin >> x;
//         if (haash[x] || x < 0 || x > N)
//             continue;
//         for (auto it = line.begin(); it != line.end(); it++)
//         {
//             if (*it == x)
//             {
//                 haash[x] = 1;
//                 line.erase(it);
//                 break;
//             }
//         }
//     }
//     for (int x : line)
//         cout << x << ' ';
// }
#include <iostream>
#include <list>
using namespace std;

const int MAXN = 1000010;
int haash[MAXN];
list<int>::iterator pos[MAXN]; // 核心优化：记录每个数的迭代器，O(1)查找

int main()
{
    ios::sync_with_stdio(false); // 加速 cin/cout
    cin.tie(0);

    list<int> line;
    int N, M;
    cin >> N;

    line.push_back(1);
    pos[1] = line.begin(); // 记录 1 的位置

    for (int i = 2; i <= N; i++)
    {
        int k, p;
        cin >> k >> p;
        auto it = pos[k]; // 直接取位置，不用遍历！

        if (p)
        {
            pos[i] = line.insert(++it, i); // insert函数返回值是新插入元素的迭代器（位置）
        }
        else
        {
            pos[i] = line.insert(it, i);
        }
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int x;
        cin >> x;
        if (haash[x] || x < 1 || x > N)
            continue;

        haash[x] = 1;
        line.erase(pos[x]); // 直接删除，不用遍历！
    }

    for (int x : line)
        cout << x << ' ';

    return 0;
}