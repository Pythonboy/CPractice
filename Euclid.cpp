/*
时间：2018/6/21 22点32分
作者：楼浩然
功能:欧几里得算法求两个数的最大公因数
变形：可以用于判断两个数是否互质
*/

#include <stdio.h>

int Euclid(int m, int n); //求m,n两个数的最大公因数

int main(void)
{
    int M,N;
    printf("请分别输入两个数，以空格分隔:\n");
    scanf("%d %d",&M,&N);
    int j; //最大公因数
    j = Euclid(M,N);
    printf("%d和%d两个数的最大公因数为:%d\n",M,N,j);
    return 0;
}

int Euclid(int m, int n)
{
    int res;
    while(n>0)
    {
        res = m%n;
        m = n;
        n = res;
    }
    return m;
}
