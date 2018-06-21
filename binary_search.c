/*
时间：2018/6/21 22点11分
作者：楼浩然
功能：对分查找
*/
#include <stdio.h>
void bubble_sort(int * a, int n); //冒泡排序

int Binary_Search(int * a, int w ,int n);  //对分查找
int main(void)
{
    int N; //数组元素个数
    printf("请输入初始数组元素个数：\n");
    scanf("%d",&N);
    int num[N]; //存放初始元素的数组
    printf("请输入%d个元素：\n",N);
    int i; //循环计数
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    bubble_sort(num,N);
    for(i=0 ; i<N ; i++)
        printf("%d ",num[i]);
    int K,j; //所需查询的元素以及对应的下标
    printf("\n请输入您所需要查询的元素:\n");
    scanf("%d",&K);
    j = Binary_Search(num,K,N);
    printf("%d在数组第%d位\n",K,j+1);
    return 0;
}

void bubble_sort(int * a, int n)
{
    int i,j; //用于循环计数
    int change; //y用于判断第二个循环中是否存在元素互换过程
    int k; //用于元素互换
    for(i = n-1 , change = 1 ; i>=1 && change ; i--)
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

int Binary_Search(int * a, int w , int n)
{
    int low,high,mid;
    low = 0,high = n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(a[mid]>w)
            high = mid;
        else if (a[mid]<w)
            low = mid;
        else
            return mid;
    }
    return -1;
}
