/*
时间：2018/6/24 15点03分
作者：楼浩然
功能：选择排序
*/

#include <stdio.h>

void InsertionSort(int * n ,int N)
{
    int i,j; //循环计数
    for(i=1 ; i<N ; i++)
    {
        int tem = n[i];
        for(j=i ; j>0 && n[j-1]>tem ; j--)
            n[j] = n[j-1];
        n[j] = tem;
    }
}

int main(void){
    int num; //元素个数
    printf("请输入元素个数：\n");
    scanf("%d",&num);
    int list[num];   // 定义一个需要排序的数组
    int i;//循环计数
    printf("请输入%d个元素：\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //读取需要排序的数字
    InsertionSort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //输出排序后的数组
    return 0;
}
