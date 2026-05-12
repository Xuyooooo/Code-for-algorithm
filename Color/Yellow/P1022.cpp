#include <iostream>
#include <string>
#include <cstdio>
int location[500];
int x, y, mid;
using namespace std;
int main()
{
    string in;
    cin >> in;
    int size = in.size(), k = 1;
    for (int i = 0; i < size; i++)
    {
        if (in[i] == '=')
            mid = i;
        if (in[i] == '+' || in[i] == '-' || in[i] == '=')
            location[k++] = i;
    }
    if (location[1] != 0)
    {

        if (in[location[1] - 1] >= 'a' && in[location[1] - 1] <= 'z')
        {
            string temp = in.substr(0, location[1] - 1);
            x += stoi(temp);
        }
        else
        {
            string temp = in.substr(0, location[1]);
            y += stoi(temp);
        }
    }
    else
    {
        for (int i = 1; i < k - 1; i++)
        {
            if (in[location[i] != '='])
            {
                if (in[location[i + 1] - 1] >= 'a' && in[location[i + 1] - 1] <= 'z')
                {
                    string temp = in.substr(location[i], location[i + 1] - location[i] - 1);
                    x += stoi(temp);
                }
                else
                {
                    string temp = in.substr(location[i], location[i + 1] - location[i]);
                    y += stoi(temp);
                }
            }
            else
                }
    }
}