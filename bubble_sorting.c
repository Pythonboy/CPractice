/*
时间：2018/6/20 14点58分
作者：楼浩然
功能：冒泡排序法原理
*/


#include <stdio.h>
void bubble_sort(int * a, int n); //冒泡排序

int main(void){
    int num; //元素个数
    printf("请输入元素个数：\n");
    scanf("%d",&num);
    int list[num];   // 定义一个需要排序的数组
    int i;//循环计数
    printf("请输入%d个元素：\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //读取需要排序的数字
    bubble_sort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //输出排序后的数组
    return 0;
}

void bubble_sort(int * a, int n)
{
    int i,j; //用于循环计数
    int change; //y用于判断第二个循环中是否存在元素互换过程
    int k; //用于元素互换
    for(i = n-1 , change = 1 ; i>1 && change ; i--)
    {
        change = 0;
        for (j=0 ; j<n-1 ; j++)
        {
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
                change = 1;
            }
        }
    }
}
