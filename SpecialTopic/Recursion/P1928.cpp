#include <iostream>
#include <string>
using namespace std;
int main()
{
    string before, after;
    cin >> before;
    int size = before.size(), state = 0, num = 1;
    for (int i = 1; i <= size; i++)
    {
        if (!state)
        {
            if (before[i] == '[')
                state = 1;
            else
                after = before[i] + after;
        }
        else
        {
            if (before[i] >= '1' && before[i] <= '9')
                num *= 1;
        }
    }
}