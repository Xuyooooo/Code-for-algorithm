#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// class score{
//    public:
//    int id;
//    int c;
//    int m;
//    int e;
//    int sum;
// };
// bool com(score a,score b)
// {
//    if(a.sum>b.sum)
//     return 1;
//      if(a.sum==b.sum&&a.c>b.c)
//      return 1;
//         if(a.sum==b.sum&&a.c==b.c&&a.id<b.id)
//         return 1;
//         return 0;
// }
// int main(){
//   score rank[100001];
//   int n;
//   cin>>n;
//   for(int i=1;i<=5;i++){
//      rank[i].id=i;
//      cin>>rank[i].c>>rank[i].m>>rank[i].e;
//      rank[i].sum=rank[i].c+rank[i].m+rank[i].e;
//   }
//   int k=5;
//   sort(rank+1,rank+6,com);
//   for(int i=6;i<=n;i++){
//      int c,m,e,s;
//      cin>>c>>m>>e;
//      s=c+m+e;
//      if(s>=rank[k].sum){
//         rank[k+1].c=c;
//         rank[k+1].m=m;
//         rank[k+1].e=e;
//         rank[k+1].sum=s;
//         rank[++k].id=i;
//         sort(rank+1,rank+k+1,com);
//      }
//   }
//   for(int i=1;i<=5;i++)
//     cout<<rank[i].id<<' '<<rank[i].sum<<endl;
// }
int main()
{
   int n, rank[301];
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      int c, m, e;
      cin >> c >> m >> e;
      rank[i++] = (c + m + e) * 10000000 + c * 1000 + n - i;
   }
   sort(rank + 1, rank + n + 1);
   for (int i = n; i > n - 5; i--)
   {
      cout << n - rank[i] % 1000 << ' ' << rank[i] << endl;
   }
}
// 这种方法
// 排名分布取决于总分+语文分+序号，则可以根据数据范围制定合适的数学式子将三者关系起来，通过大小来观察排名
