// 双端队列
#include <iostream>
#include <deque> //双端队列使用所需头文件
using namespace std;
int main()
{
   deque<int> dq = {0, 1, 3, 4, 5, 6};
   cout << dq.front() << endl; // 返回队列队头元素
   dq.push_front(7);           // 对头加元素
   cout << dq.front() << endl;
   dq.pop_front(); // 删除对头元素
   cout << dq.front() << endl;
   cout << dq[3] << endl;    // 返回下标为i元素
   dq.insert(dq.begin(), 8); // 在指定位置插入元素
   cout << dq[0] << endl;
   // dq.insert(dq.begin(),n,8);----在指定位置插入n个8
   dq.erase(dq.begin()); // 删除指定位置的值
   // dq.erase(dq.begin(),dq.end());---删除左闭右开区间的所有元素
   cout << dq[0] << endl;
   return 0;
}