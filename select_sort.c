/*
ʱ�䣺2018/6/20 14��39��
���ߣ�¥��Ȼ
���ܣ�ʵ��ѡ������
ʱ�临�Ӷȣ�O(n2)
*/

#include <stdio.h>

void select_sort(int * a ,int n); //ѡ������

int main(void){
    int num; //Ԫ�ظ���
    printf("������Ԫ�ظ�����\n");
    scanf("%d",&num);
    int list[num];   // ����һ����Ҫ���������
    int i;//ѭ������
    printf("������%d��Ԫ�أ�\n",num);
    for(i=0 ; i<num ; i++)
        scanf("%d",&list[i]);    //��ȡ��Ҫ���������
    select_sort(list,num);
    for(i=0 ; i<num ; i++)
        printf("%d%c",list[i],i!=num-1?' ':'\n');  //�������������
    return 0;
}

void select_sort(int * a ,int n){
    int i,j ; //ѭ������
    int k; //����Ԫ��ʱʹ��
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
