/*
时间：2018/7/23
作者：楼浩然
功能：冒泡排序
*/

#include <iostream>
using namespace std;

void Swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[],int N)
{
    int i,j,flag = 1;
    for(i=N-1 ; flag && i>0 ; i--)
    {
        flag = 0;
        for(j=0 ; j<i ; j++)
        {
            if(A[j] > A[j+1])
            {
                Swap(A[j],A[j+1]);
                flag = 1;
            }
        }
    }
}

int main()
{
    int A[10] = {10,5,6,2,4,3,7,9,8,1};
    BubbleSort(A,10);
    int i;
    for(i=0 ; i<10 ; i++)
        cout<<A[i]<<" ";
    return 0;
}

