/*
ʱ�䣺2018/6/21 23��42��
���ߣ�¥��Ȼ
���ܣ���������洢��Ӱ���ƺ����֣��������Ϣ
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

char * s_gets(char * s, int N);  //���뺯��

struct film{
    char name[SIZE];
    int rating;
    struct film * next;
};

int main(void)
{
    struct film * head = NULL;
    struct film *prev,*current;
    char Input[SIZE];
    printf("�������һ����Ӱ������:(q�˳�)\n");
    while(s_gets(Input,SIZE)!=NULL && Input[0]!='\0'&& Input[0]!='q')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if(head!=NULL)
            prev->next = current;
        else
            head = current;
        strcpy(current->name,Input);
        current->next = NULL;
        printf("�������Ӱ���֣�1-10��:\n");
        scanf("%d",&current->rating);
        while(getchar()!='\n')
            continue;
        prev = current;
        printf("����������Ӱ��Ϣ��(q�˳�)\n");
    }
    if(head==NULL)
        printf("û�������κε�Ӱ��Ϣ\n");
    else
    {
        printf("����������ĵ�Ӱ��Ϣȫ������:\n");
        current = head;
        while(current)
        {
            printf("\tName:%s\trating:%d\n",current->name,current->rating);
            current = current->next;
        }
    }
    current = head;
    while(current)
    {
        free(current);
        current = current->next;
    }
    return 0;

}

char * s_gets(char * s, int N)
{
    char *res,*find;
    res = fgets(s,N,stdin);
    if(res){
        find = strchr(s,'\n');
        if(find)
            *find = '\0';
        else
        {
            while(getchar()!='\n')
                continue;
        }
    }
    return res;


}
