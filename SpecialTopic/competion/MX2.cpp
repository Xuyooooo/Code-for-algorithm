#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
   int c,t;
   cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        long long n,a,b;
        cin>>n>>a>>b;
       if(n==0)
       {
         cout<<ceil(a*1.0/(2*b+1))<<endl; 
       }
       else if(n>0)
       {
          if(0>=(long long)ceil((a*1.0-2*n*b)/(2*b+1)))
          long long t=0;
          else
           t=ceil((a*1.0-2*n*b)/(2*b+1));
          cout<<t+n<<endl;
       }
      else if(n<0)
     {
        if(0>=ceil((a*1.0+2*n+2*n*b)/(2*b+1)))
        long long t=0;
        else 
        t=ceil((a*1.0+2*n+2*n*b)/(2*b+1));
      cout<<t-n<<endl;
     }  
    }
}