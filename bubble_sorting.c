/*
ʱ�䣺2018/6/20 14��58��
���ߣ�¥��Ȼ
���ܣ�ð������ԭ��
*/


#include <stdio.h>
void bubble_sort(int * a, int n); //ð������

int main(void){
    int num; //Ԫ�ظ���
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&num);
    int list[num];   // ����һ����Ҫ���������
    int i;//ѭ������
    printf("������%d��Ԫ�أ�\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //��ȡ��Ҫ���������
    bubble_sort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //�������������
    return 0;
}

void bubble_sort(int * a, int n)
{
    int i,j; //����ѭ������
    int change; //y�����жϵڶ���ѭ�����Ƿ����Ԫ�ػ�������
    int k; //����Ԫ�ػ���
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
