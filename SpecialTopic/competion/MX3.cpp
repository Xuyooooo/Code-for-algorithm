#include<bits/stdc++.h>
using namespace std;
void jisuan(int *a,int *b,int v,int p)
{
      if(v>=a[1]-b[1])
        b[1]=a[1];
        else
        b[1]+=v;
        int l;
        for(l=2;l<=p;l++)
        {
            if(b[l-1]>=a[l]-b[l])
            b[l]=a[l];
            else
            b[l]+=b[l-1];
        }
        cout<<b[l-1];
}
int main()
{
   int c,t;
   cin>>c>>t;
   for(int i=1;i<=t;i++)
   {
     int n,q;
     cin>>n>>q;
     int *a=new int[n+1];
     int *b=new int[n+1];
     for(int j=1;j<=n;j++)
       cin>>a[j]>>b[j];
     for(int k=1;k<=q;k++)
     {
        int v,p;
        cin>>v>>p;
        jisuan(a,b,v,p);
     }
     delete[] a;
     delete[] b;
   }
}