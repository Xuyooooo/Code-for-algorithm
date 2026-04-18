#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string output;
void tree(string input, int start, int end)
{
    int mid = start + ((end - start) >> 1);
    if (start < end)
        tree(input, mid + 1, end);
    int i = start;
    while (i < end)
    {
        if (input[i + 1] == input[i])
            i++;
        else
            break;
    }
    if (i == end)
    {
        if (input[i] == '0')
            output = output + 'B';
        else
            output = output + 'I';
    }
    else
        output = output + 'F';
    if (start < end)
        tree(input, start, mid);
}
int main()
{
    int N, start = 0, end;
    cin >> N;
    end = pow(2, N) - 1;
    string input;
    cin >> input;
    tree(input, start, end);
    cout << output;
}