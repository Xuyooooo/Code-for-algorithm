#include<bits/stdc++.h>
using namespace std;
class line{
    public:
    int num;
    line *next;
};
int main()
{
    list<int>line1(5,3);
    line1.push_back(2);
    line1.push_front(1);
    line1.remove(3);
   for(auto it=line1.begin();it!=line1.end();it++)
   {
     line1.insert(it,6);
   }
   for(int x:line1)
    cout<<x<<' ';
    line1.reverse();
      for(int x:line1)
    cout<<x<<' ';
    line1.sort();
     for(int x:line1)
    cout<<x<<' ';
    int n,m;
    cin>>n>>m;
    line * head,* now,* prev ,* p;
    head=new line;
    head->num=1;
    head->next=NULL;
    now=head;
   for(int i=2;i<=n;i++)
   {
        p=new line;
        p->num=i;
        p->next=NULL;
        now->next=p;
        now=p;
   }
   now->next=head;
   now=head,prev=head;
   while((n--)>1)
   {
     for(int i=1;i<m;i++)
     {
        prev=now;
        now=now->next;
     }
     cout<<now->num<<' ';
     prev->next=now->next;
     delete now;
     now=prev->next;
   }
    cout<<now->num;
    delete now;
    return 0;
}