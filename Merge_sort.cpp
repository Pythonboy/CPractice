/*
时间：2018/7/22
作者：楼浩然
功能：归并排序
实现方式：递归
*/

#include <iostream>
using namespace std;

void Merging(int * left,int leftsize,int * right,int rightsize)
{
    int temp[leftsize+rightsize];
    int i=0,z=0;
    int k = 0;
    while(i<leftsize&&z<rightsize)
    {
        if(left[i]<right[z])
            temp[k++] = left[i++];
        else
            temp[k++] = right[z++];
    }
    while(i<leftsize)
        temp[k++] = left[i++];
    while(z<rightsize)
        temp[k++] = right[z++];
    for(i=0 ; i<leftsize+rightsize ; i++)
        left[i] = temp[i];
}

void MergeSort(int A[],int K)
{
    if(K<=1)
        return ;
    int leftsize = K/2;
    int rightsize = K - leftsize;
    int * left = A;
    int * right = A+leftsize;
    MergeSort(left,leftsize);
    MergeSort(right,rightsize);
    Merging(left,leftsize,right,rightsize);
}

int main()
{
    int A[10] = {10,5,2,6,3,9,15,13,16,17};
    MergeSort(A,10);
    for(auto c :A)
        cout<<c<<" ";
    return 0;
}
