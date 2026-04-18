#include<iostream>
using namespace std;
int main()
{
   int N,Na,Nb,A_score=0,B_score=0;
   cin>>N>>Na>>Nb;
   int* circle_A=new int[Na];
   int* circle_B=new int[Nb];
   int compartion[]={4,0,2,3,1};
   for(int i=0;i<Na;i++)
   {
     cin>>circle_A[i];
   }
   for(int i=0;i<Nb;i++)
   {
     cin>>circle_B[i];
   }
   for(int i=0;i<N;i++)
   {
      if(compartion[circle_A[i%Na]]==compartion[circle_B[i%Nb]])
       ;
      else if(compartion[circle_A[i%Na]]-compartion[circle_B[i%Nb]]>0)
      {
        if(compartion[circle_A[i%Na]]-compartion[circle_B[i%Nb]]<=2)
        A_score++;
        else
        B_score++;
      }
      else if(compartion[circle_A[i%Na]]-compartion[circle_B[i%Nb]]<0)
      {
        if(compartion[circle_B[i%Na]]-compartion[circle_A[i%Nb]]>=2)
        B_score++;
        else
        A_score++;
      }
   }
    cout<<A_score<<' '<<B_score<<endl;
   delete[] circle_A;
   delete[] circle_B;
}