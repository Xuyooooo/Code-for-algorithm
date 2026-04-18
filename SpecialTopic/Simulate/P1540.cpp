#include<iostream>
#include<queue>
int numm[100001];
using namespace std;
int main()
{
    queue<int>memory;
    int M,N,num=0;
    cin>>M>>N;
    for(int i=1;i<=N;i++)
    {
        int temp;
        cin>>temp;
        if(memory.size()>=3)
        {
              if(!numm[temp])
              {
                numm[temp]=1;
                numm[memory.front()]=0;
                memory.pop();
                memory.push(temp);
                num++;
              }
        }
        else
        {
              if(!numm[temp])
              {
                numm[temp]=1;
                memory.push(temp);
                num++;
              }
        }

    }
   cout<<num;


}