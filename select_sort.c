/*
时间：2018/6/20 14点39分
作者：楼浩然
功能：实现选择排序法
时间复杂度：O(n2)
*/

#include <stdio.h>

void select_sort(int * a ,int n); //选择排序

int main(void){
    int num; //元素个数
    printf("请输入元素个数：\n");
    scanf("%d",&num);
    int list[num];   // 定义一个需要排序的数组
    int i;//循环计数
    printf("请输入%d个元素：\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //读取需要排序的数字
    select_sort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //输出排序后的数组
    return 0;
}

void select_sort(int * a ,int n){
    int i,j ; //循环计数
    int k; //互换元素时使用
    for (i=0 ; i<n-1 ; i++)
    {
        for (j=i+1 ; j<n ; j++)
        {
            if(a[j] < a[i])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
}
