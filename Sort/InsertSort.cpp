/*
时间：2018/7/23
作者：楼浩然
功能：插入排序
*/

#include <iostream>
using namespace std;

void InsertSort(int A[],int N)
{
    int i,j;
    for(i=1 ; i<N ; i++)
    {
        int temp = A[i];
        for(j=i ; j>0 ; j--)
        {
            if(A[j-1]>temp)
                A[j] = A[j-1];
            else
                break;
        }
        A[j] = temp;
    }
}

int main()
{
    int A[10] = {10,5,6,2,4,3,7,9,8,1};
    InsertSort(A,10);
    int i;
    for(i=0 ; i<10 ; i++)
        cout<<A[i]<<" ";
    return 0;
}
