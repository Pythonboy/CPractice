/*
ʱ�䣺2018/6/24 15��03��
���ߣ�¥��Ȼ
���ܣ�ѡ������
*/

#include <stdio.h>

void InsertionSort(int * n ,int N)
{
    int i,j; //ѭ������
    for(i=1 ; i<N ; i++)
    {
        int tem = n[i];
        for(j=i ; j>0 && n[j-1]>tem ; j--)
            n[j] = n[j-1];
        n[j] = tem;
    }
}

int main(void){
    int num; //Ԫ�ظ���
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&num);
    int list[num];   // ����һ����Ҫ���������
    int i;//ѭ������
    printf("������%d��Ԫ�أ�\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //��ȡ��Ҫ���������
    InsertionSort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //�������������
    return 0;
}
