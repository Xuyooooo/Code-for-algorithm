#include <iostream>
#include <string>
using namespace std;
int main()
{
   int n, max = 1;
   cin >> n;
   string vote[1001];
   for (int i = 1; i <= n; i++)
   {
      cin >> vote[i];
      max = vote[i].size() > vote[max].size() ? i : max;
      if (vote[i].size() == vote[max].size())
         max = vote[i] > vote[max] ? i : max;
   }
   cout << max << endl
        << vote[max];
}