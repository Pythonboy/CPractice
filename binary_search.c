/*
ʱ�䣺2018/6/21 22��11��
���ߣ�¥��Ȼ
���ܣ��Էֲ���
*/
#include <stdio.h>
void bubble_sort(int * a, int n); //ð������

int Binary_Search(int * a, int w ,int n);  //�Էֲ���
int main(void)
{
    int N; //����Ԫ�ظ���
    printf("�������ʼ����Ԫ�ظ�����\n");
    scanf("%d",&N);
    int num[N]; //��ų�ʼԪ�ص�����
    printf("������%d��Ԫ�أ�\n",N);
    int i; //ѭ������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    bubble_sort(num,N);
    for(i=0 ; i<N ; i++)
        printf("%d ",num[i]);
    int K,j; //�����ѯ��Ԫ���Լ���Ӧ���±�
    printf("\n������������Ҫ��ѯ��Ԫ��:\n");
    scanf("%d",&K);
    j = Binary_Search(num,K,N);
    printf("%d�������%dλ\n",K,j+1);
    return 0;
}

void bubble_sort(int * a, int n)
{
    int i,j; //����ѭ������
    int change; //y�����жϵڶ���ѭ�����Ƿ����Ԫ�ػ�������
    int k; //����Ԫ�ػ���
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
