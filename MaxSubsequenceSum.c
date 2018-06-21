/*
时间：2018/6/21 21点08分
作者:楼浩然
功能：解决最大子序列问题
*/

#include <stdio.h>

int for_use(int * a, int n); //通过for循环求出最大序列和，时间复杂度为O(n2),不可取

int Max(int m,int n, int j); //divide_and_conquer中需要调用的函数，返回三个数中最大的值

int divide_and_conquer(int * a, int left, int right); // 采用分而治之的策略，利用递归求得最大子序列和，时间复杂度为O(NlogN),其中的思想值得好好学习

int perfect(int * a, int n); //最优解法，时间复杂度为O(N);

int main(void)
{
    int N; //序列的元素个数
    printf("请输入元素个数：\n");
    scanf("%d",&N);
    int num[N];//存放序列元素
    printf("请输入%d个元素的值:\n",N);
    int i; // 循环计数
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    int Re1,Re2,Re3; //求出的最大子序列和的值
    Re1 = for_use(num,N);
    Re2 = divide_and_conquer(num,0,N-1);
    Re3 = perfect(num,N);

    printf("%d %d %d",Re1,Re2,Re3);
    return 0;
}

int for_use(int * a, int n)
{
    int i,j; //循环计数用
    int max_sum = 0 ; //最大序列和
    int res; //中间计算的序列和
    for(i=0 ; i<n ; i++)
    {
        res = 0;
        for(j=i ; j<n ; j++)
        {
            res += a[j];
            if(res > max_sum)
                max_sum = res;
        }
    }
    return max_sum;
}

int Max(int m,int n, int j)
{
    if(m>=n && m>=j)
        return m;
    else if (n>=m && n>=j)
        return n;
    else
        return j;
}

int divide_and_conquer(int * a, int left, int right)
{
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int center,i;
    if(left == right)
    {
        if(a[left]>0)
            return a[left];
        else
            return 0;
    }
    center = (left + right)/2;
    MaxLeftSum = divide_and_conquer(a,left,center);
    MaxRightSum = divide_and_conquer(a,center+1,right);
    MaxLeftBorderSum = 0,LeftBorderSum = 0;
    for(i=center ; i>=left ; i--)
    {
        LeftBorderSum += a[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    MaxRightBorderSum = 0,RightBorderSum = 0;
    for(i=center+1 ; i<=right ; i++)
    {
        RightBorderSum += a[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    return Max(MaxLeftSum,MaxRightSum,MaxRightBorderSum+MaxLeftBorderSum);
}


int perfect(int * a, int n)
{
    int MaxSequenceSum,ThisSequenceSum,j;
    MaxSequenceSum = ThisSequenceSum = 0;
    for(j=0 ; j<n ; j++)
    {
        ThisSequenceSum += a[j];
        if(ThisSequenceSum > MaxSequenceSum )
            MaxSequenceSum = ThisSequenceSum ;
        else if(ThisSequenceSum < 0 )
            ThisSequenceSum  = 0;
    }
    return MaxSequenceSum ;
}
