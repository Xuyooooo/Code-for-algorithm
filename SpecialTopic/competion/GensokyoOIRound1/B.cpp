
#include <iostream>
// #include <deque>
#include <vector>
using namespace std;
int minn = 1000;
void dfs(int k, int now, int *p, deque<int> a)
{
    vector<int> a;
    a.
}
int main()
{
    int n, temp, sum = 0, save;
    vector<int> a;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        cin >> temp;
        if (temp)
            a.push_back(temp);
        else
        {
            int temp1;
            cin >> temp1;
            int k = 1;
            while (!temp1)
            {
                k++;
                i++;
                cin >> temp1;
            }
            save = temp1;
            if (k == 1)
            {
                if (a.front() <= a.back())
                    a.pop_back();
                else
                    a.pop_back();
            }
            else
            {
                deque<int> copy = a;
                int p[20] = {0};
            }
        }
        i++;
    }

    while (!a.empty())
    {
        sum += a.front();
        a.pop_front();
    }
    cout << sum << '\n';
    return 0;
}