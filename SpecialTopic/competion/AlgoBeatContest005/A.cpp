// https://www.luogu.com.cn/problem/P16429?contestId=316306

#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ok = 1;
        string in, ot;
        cin >> in >> ot;
        if (in.size() != 7)
            ok = 2;
        else
        {
            if (in[3] < '0' || in[3] > '9' || in[4] < '0' || in[4] > '9' || in[5] < '0' || in[5] > '9' || in[6] < '0' || in[6] > '9')
                ok = 2;
            if (in[3] == in[4] && in[4] == in[5] && in[5] == in[6] && in[6] == '0')
                ok = 2;
            // string num = in.substr(3, 4);
            // int x = stoi(num);
            // if (x < 1 || x > 9999)
            //     ok = 2;
        }
        if (ok == 1)
        {
            if (ot.size() < 6)
            {
                ok = 3;
            }
            else
            {
                int a = 0, b = 0, c = 0;
                for (int i = 0; i < ot.size(); i++)
                {
                    if (ot[i] >= '0' && ot[i] <= '9')
                        a = 1;
                    if (ot[i] >= 'a' && ot[i] <= 'z')
                        b = 1;
                    if (ot[i] >= 'A' && ot[i] <= 'Z')
                        c = 1;
                }
                if (a + b + c != 3)
                    ok = 3;
            }
        }
        if (ok == 1)
            cout << "Accept" << '\n';
        else if (ok == 2)
            cout << "Wrong Name" << '\n';
        else
            cout << "Wrong Password" << '\n';
    }
    return 0;
}