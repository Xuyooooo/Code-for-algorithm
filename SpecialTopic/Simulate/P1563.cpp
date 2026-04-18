#include<iostream>
using namespace std;
class toy{
    public:
    bool direction;
    string profession;
};
int main(){
    int n,m,location=0;
    cin>>n>>m;
    toy* toys=new toy[n];
    for(int i=0;i<n;i++){
        cin>>toys[i].direction;
        getchar();
        cin>>toys[i].profession;
    }
    for(int i=1;i<=m;i++){
        int a,s;
        cin>>a>>s;
        if(a)
        {
           if(toys[i].direction)
           {
            if(location-s<0)
            location=n+location-s;
            else
            location-=s;
           }
           else
           {
            location=(location+s)%n;
           }
        }
        else
        {
          if(toys[i].direction)
           {
              location=(location+s)%n; 
           }
           else
           {
           if(location-s<0)
            location=n+location-s;
            else
            location-=s;
           }
        }
    }
   cout<<toys[location].profession<<endl;
   delete []toys;
}