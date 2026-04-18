#include <iostream>
using namespace std;
int main()
{
    int N, num = 0, if_swap = 0;
    cin >> N;
    int *train = new int[N];
    for (int i = 0; i < N; i++)
        cin >> train[i];
    // 这是冒泡排序的第一种优化方法，加入变量来判断一轮是否一次都没有交换
    //  for (int i = 0; i < N - 1; i++)
    //  {
    //      for (int j = 0; j < N - 1 - i; j++)
    //      {
    //          if (train[j] > train[j + 1])
    //          {
    //              num++;
    //              int temp = train[j];
    //              train[j] = train[j + 1];
    //              train[j + 1] = train[j];
    //              if_swap = 1;
    //          }
    //      }
    //      if (!if_swap)
    //          break;
    //  }
    // 第二种优化方法，每次记录最后一次交换位置，下一次交换到那里即可
    int k = N - 1;
    for (int i = 0; i < N - 1; i++)
    {
        int last_swap_location = 0;
        for (int j = 0; j < k; j++)
        {
            if (train[j] > train[j + 1])
            {
                num++;
                int temp = train[j];
                train[j] = train[j + 1];
                train[j + 1] = temp;
                last_swap_location = j;
            }
        }
        k = last_swap_location;
        if (k == 0)
            break;
    }
    // 第三种优化方法，双向冒泡,可以解决小数字在最右边挪不动的问题
    //     int left=0,right=N-1;
    //     while(left<right)
    //     {
    //         for(int i=left;i<right;i++)
    //         {
    //             if(train[i]>train[i+1])
    //                 swap(train[i],train[i+1]);
    //         }
    //         right--;
    //         for(int i=right;i >left ;i--)
    //         {
    //             if(train[i[i]<train[i-1]])
    //             swap( train[i],train[i-1]);
    //         }
    //             left--;
    //     }
    cout << num;
    delete[] train;
    return 0;
}