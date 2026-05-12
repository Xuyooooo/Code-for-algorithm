// https://www.luogu.com.cn/problem/P7765

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int location1, location2;
    vector<int> aa(26, -1);
    for (int i = 0; i < a.size(); i++)
    {
        if (aa[a[i] - 'A'] == -1)
            aa[a[i] - 'A'] = i;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (aa[b[i] - 'A'] != -1)
        {
            location1 = i;
            location2 = aa[b[i] - 'A'];
            break;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (i != location1)
        {
            for (int j = 0; j < a.size(); j++)
            {
                if (j == location2)
                    cout << b[i];
                else
                    cout << '.';
            }
            cout << '\n';
        }
        else
            cout << a << '\n';
    }
    return 0;
}