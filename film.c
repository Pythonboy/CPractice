/*
时间：2018/6/21 23点42分
作者：楼浩然
功能：利用链表存储电影名称和评分，并输出信息
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

char * s_gets(char * s, int N);  //输入函数

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
    printf("请输入第一部电影的名称:(q退出)\n");
    while(s_gets(Input,SIZE)!=NULL && Input[0]!='\0'&& Input[0]!='q')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if(head!=NULL)
            prev->next = current;
        else
            head = current;
        strcpy(current->name,Input);
        current->next = NULL;
        printf("请输入电影评分（1-10）:\n");
        scanf("%d",&current->rating);
        while(getchar()!='\n')
            continue;
        prev = current;
        printf("请继续输入电影信息：(q退出)\n");
    }
    if(head==NULL)
        printf("没有输入任何电影信息\n");
    else
    {
        printf("以下是输入的电影信息全部内容:\n");
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
