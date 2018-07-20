/*
时间：2018/7/20
作者：楼浩然
功能：利用数组实现二叉树存储
*/
#include <iostream>
#include <vector>
using namespace std;

void CreateBTree(int *List, int *BT,int n)
{
    int i,order = 1;
    BT[1] = List[0];
    for(i=1 ;i<n ; i++)
    {
        order = 1;
        while(BT[order]!=0)
        {
            if(BT[order]>List[i])
                order = order * 2;
            else
                order = order * 2 + 1;
        }
        BT[order] = List[i];
    }
}

int main()
{
    int Origin[10] = {5,3,4,8,12,2,9,7,6,10};
    int BT[100] = {0};
    CreateBTree(Origin,BT,10);
    int i;
    for(i=0 ; i<100 ; i++)
    {
        if(BT[i]!=0)
            cout<<BT[i]<<" ";
    }
    return 0;
}
