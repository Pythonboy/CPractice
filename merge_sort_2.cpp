/*
时间：2018/7/22
作者：楼浩然
功能：归并排序
实现方式：迭代
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void MergeSort(int A[],int N)
{
    int left_min,left_max,right_min,right_max;
    int i;
    int * temp = (int *)malloc(sizeof(int)*N);
    for(i=1 ; i<N ; i*=2)
    {
        for(left_min = 0 ; left_min < N-i ; left_min = right_max)
        {
            left_max = right_min = left_min + i;
            right_max = right_min + i;
            if(right_max>N)
                right_max = N;
            int k = 0;
            while(left_min < left_max && right_min < right_max)
            {
                if(A[left_min] < A[right_min])
                    temp[k++] = A[left_min++];
                else
                    temp[k++] = A[right_min++];
            }
            while(left_min < left_max)
            {
                A[--right_min] = A[--left_max];
            }
            while(k>0)
            {
                A[--right_min] = temp[--k];
            }
        }
    }
}

int main()
{
    int A[10] = {10,9,8,7,6,5,4,3,2,1};
    MergeSort(A,10);
    for(auto c :A)
        cout<<c<<" ";
    return 0;
}
