/*
ʱ�䣺2018/6/21 21��08��
����:¥��Ȼ
���ܣ�����������������
*/

#include <stdio.h>

int for_use(int * a, int n); //ͨ��forѭ�����������кͣ�ʱ�临�Ӷ�ΪO(n2),����ȡ

int Max(int m,int n, int j); //divide_and_conquer����Ҫ���õĺ���������������������ֵ

int divide_and_conquer(int * a, int left, int right); // ���÷ֶ���֮�Ĳ��ԣ����õݹ������������кͣ�ʱ�临�Ӷ�ΪO(NlogN),���е�˼��ֵ�úú�ѧϰ

int perfect(int * a, int n); //���Žⷨ��ʱ�临�Ӷ�ΪO(N);

int main(void)
{
    int N; //���е�Ԫ�ظ���
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&N);
    int num[N];//�������Ԫ��
    printf("������%d��Ԫ�ص�ֵ:\n",N);
    int i; // ѭ������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    int Re1,Re2,Re3; //�������������к͵�ֵ
    Re1 = for_use(num,N);
    Re2 = divide_and_conquer(num,0,N-1);
    Re3 = perfect(num,N);

    printf("%d %d %d",Re1,Re2,Re3);
    return 0;
}

int for_use(int * a, int n)
{
    int i,j; //ѭ��������
    int max_sum = 0 ; //������к�
    int res; //�м��������к�
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
