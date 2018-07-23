/*
时间：2018/7/22
作者：楼浩然
功能：堆排序
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define LeftChild(i) (2*i+1)

void PercDown(int A[],int i,int N)
{
    int Child;
    int Temp;
    for(Temp = A[i] ; LeftChild(i)<N ; i = Child)
    {
        Child = LeftChild(i);
        if(Child != N-1 &&A[Child]<A[Child + 1])
            Child++;
        if(Temp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Temp;
}

void Swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void HeapSort(int A[],int N)
{
    int i;
    for(i = N/2 ; i>=0 ; i--)   //build Heap
    {
        PercDown(A,i,N);
    }
    for(i = N - 1; i>0 ; i--)   //DeleteMax
    {
        Swap(A[0],A[i]);
        PercDown(A,0,i);
    }
}

int main()
{
    int A[10] = {10,5,2,4,6,12,3,9,8,7};
    HeapSort(A,10);
    for(auto i : A)
        cout<<i<<" ";
    return 0;
}
