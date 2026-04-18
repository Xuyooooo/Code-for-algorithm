#include<iostream>
using namespace std;
void merge(int*,int,int,int);
void sort(int *arr,int start,int end)
{
   if(start>=end)
   return;
   int mid=start+((end-start)>>1);
   sort(arr,start,mid);
   sort(arr,mid+1,end);
   merge(arr,start,mid,end);

}
void merge(int *arr,int start,int mid,int end)
{
  int p1=start,p2=mid+1,i=0;
  int *temp=new int[end-start+1];
  while(p1<=mid&&p2<=end)
  {
    arr[p1]<=arr[p2]?temp[i++]=arr[p1++]:temp[i++]=arr[p2++];
  }
  while(p1<=mid)
    temp[i++]=arr[p1++];
  while (p2<=end)
    temp[i++]=arr[p2++];
  for(int j=0;j<end-start+1;j++)
    arr[start+j]=temp[j];
}
int main()
{
  int N;
  cin>>N;
  int *arr=new int [N];
  for(int i=0;i<N;i++)
  cin>>arr[i];
  sort(arr,0,N-1);
  for(int i=0;i<N;i++)
  cout<<arr[i]<<' ';
delete[] arr;
}