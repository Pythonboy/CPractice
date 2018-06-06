/*
作者：楼浩然
功能：冒泡排序法原理
*/


#include <stdio.h>
void sort(int *Aprr, int len)
{
    int i ;
    int j ;
    int t;
    for (i = 0; i < len ; i++)
    {
        for ( j = len - 1; j > i ; j--)
        {
            if (Aprr[i]>Aprr[j])
            {
                t = Aprr[i];
                Aprr[i] = Aprr[j];
                Aprr[j] = t;
            }
        }
    }
}
int main(void)
{
    int a[5] = {6, 10, 4, 7, 2};
    sort(a,sizeof(a)/4);
    int i;
    for (i = 0; i < sizeof(a)/4; i++)
        printf("%d ",a[i]);
    return 0;

}
