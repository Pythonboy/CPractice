/*
ʱ�䣺2018/6/21 22��32��
���ߣ�¥��Ȼ
����:ŷ������㷨�����������������
���Σ����������ж��������Ƿ���
*/

#include <stdio.h>

int Euclid(int m, int n); //��m,n���������������

int main(void)
{
    int M,N;
    printf("��ֱ��������������Կո�ָ�:\n");
    scanf("%d %d",&M,&N);
    int j; //�������
    j = Euclid(M,N);
    printf("%d��%d���������������Ϊ:%d\n",M,N,j);
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
