/*
时间：2018/7/23
作者：楼浩然
功能：选择排序
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

void SelectionSort(int A[],int N)
{
    int i,j,flag = 1 ;
    for(i=0 ; flag && i<N-1 ; i++)
    {
        flag = 0;
        for(j=i+1 ; j<N ; j++)
        {
            if(A[j]<A[i])
            {
                Swap(A[i],A[j]);
                flag = 1;
            }
        }
    }
}

int main()
{
    int A[10] = {10,5,6,2,4,3,7,9,8,1};
    SelectionSort(A,10);
    int i;
    for(i=0 ; i<10 ; i++)
        cout<<A[i]<<" ";
    return 0;
}
