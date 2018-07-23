/*
时间：2018/7/23
作者：楼浩然
功能：希尔排序
*/

#include <iostream>
using namespace std;

void ShellSort(int A[],int N)
{
    int i,j,increment;
    int temp;
    for(increment = N/2 ; increment > 0 ; increment /= 2)
    {
        for( i=increment ; i<N ; i++)
        {
            temp = A[i];
            for(j=i ; j>=increment ; j-=increment)
            {
                if(A[j-increment]>temp)
                    A[j] = A[j-increment];
                else
                    break;
            }
            A[j] = temp;
        }
    }
}

int main()
{
    int A[10] = {10,5,6,2,4,3,7,9,8,1};
    ShellSort(A,10);
    int i;
    for(i=0 ; i<10 ; i++)
        cout<<A[i]<<" ";
    return 0;
}
