#include<iostream>
using namespace std;
int main(){
    int n,m,k=1;
    cin>>n>>m;
    int** matrix=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        matrix[i]=new int [n+1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          matrix[i][j]=k++;
        }
    }
    for(int i=1;i<=m;i++)
    {
      int x,y,r,z;
      cin>>x>>y>>r>>z;
    if(z)
    {
        for(int j=x-r;j<=x+r;j++)
        {
            int o=
            for(int l=y-r;l<=y+r;l++)
            {

            }
        }
    }

    }

}