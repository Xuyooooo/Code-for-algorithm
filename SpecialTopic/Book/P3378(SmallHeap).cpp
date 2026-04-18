//P3378堆
//也是优先队列中的小顶堆的模板
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;//这为小顶堆，greater为更大的，即更大的在后面
int main(){
      int n;
      cin>>n;
for(int i=1;i<=n;i++){
    int op;
    cin>>op;
    if(op==1){
        int x;
        cin>>x;    
        q.push(x);
    }
    else if(op==2)
    cout<<q.top()<<endl;
    else
    q.pop();
}
 return 0;
}