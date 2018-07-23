/*
时间：2018/7/22
作者：楼浩然
功能：原始的快速排序
*/

#include <iostream>
using namespace std;

void Swap(int &low,int &high)
{
    int temp;
    temp = low;
    low = high;
    high = temp;
}

int Patition(int A[],int low ,int high)
{
    int a = A[low];
    int b = A[high];
    int d = A[(low+high)/2];
    if(a>d)
        Swap(A[low],A[(low+high)/2]);
    if(b>d)
        Swap(A[high],A[(low+high)/2]);
    if(a>b)
        Swap(A[low],A[(low+high)/2]);
    int point = A[low];
    while(low < high)
    {
        while(low < high && A[high] >= point)
            high--;
        Swap(A[low],A[high]);
        while(low < high && A[low] <= point)
            low++;
        Swap(A[low],A[high]);
    }
}

void Qsort(int A[],int low,int high)
{
    int point;
    if(low < high)
    {
        point = Patition(A,low,high);
        Qsort(A,low,point-1);
        Qsort(A,point+1,high);
    }
}

void QuickSort(int A[],int N)
{
    Qsort(A,0,N-1);
}

int main()
{
    int A[10] = {10,5,2,6,3,9,15,13,16,17};
    QuickSort(A,10);
    for(auto c :A)
        cout<<c<<" ";
    return 0;
}
