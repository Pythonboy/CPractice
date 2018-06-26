/*
时间：2018/6/25 17点00分
作者：楼浩然
功能：利用链表实现表ADT
1.判断链表是否为空
2.判断节点是否为链表末尾
3.在链表的P位置后插入一个元素
4.找到元素X的节点位置或找到元素X之前的节点位置
5.删除元素X所在的节点
6.删除链表
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

typedef struct Item{
    char Name[SIZE];
    int rating ;
}Item;

typedef struct Node{
    Item item;
    struct Node * next;
}Node;

typedef Node * List;
typedef Node * Position;

List MakeEmpty(List L);
int IsEmpty(List L);  //判断列表是否为空
int IsLast(Position P,List L); //判断是否为列表的末尾
Position Find(Item X, List L);  //寻找到这个节点
Position FindPrevious(Item X,List L);  //寻找到X元素之前的节点
void Delete(Item X,List L); //删除X元素所在的节点

void insert(Item X, List L, Position P);//链表的插入，在P位置之后
void DeleteList(List L);
Position Header(List L);
Position Advance(Position P);
Position First(List L);
char *s_gets(char * r, int N);

int main(void)
{
    char Input[SIZE];
    List head;
    head = NULL;
    List current,prev;
    if(IsEmpty(head))
    printf("此时表头为空\n");
    printf("请输入电影名称：（q退出)\n");
    while(s_gets(Input,SIZE)!=NULL && Input[0]!='\0' && Input[0]!='q')
    {
        Item mid;
        current = (List)malloc(sizeof(Node));      //sizeof()里面放结构体，不要放指针
        strcpy(mid.Name,Input);
        printf("请为该电影打分：(0-10)\n");
        scanf("%d",&mid.rating);
        while(getchar()!='\n')
            continue;      //这一段必须要有，否则会把'\n'保存下来，下一步电影信息就无法输入了
        current->item = mid;
        current->next = NULL;
        if(head==NULL)
            head = current;
        else
            prev->next = current;
        prev = current;
        printf("请输入电影名称：（q退出)\n");
    }

    printf("是否有需要删除的电影：1为是0为退出:\n");
    int xz;
    scanf("%d",&xz);
    while(xz)
    {
        printf("请输入需要删除的电影名称：\n");
        Item S;
        scanf("%s",&Input);
        strcpy(S.Name,Input);
        Delete(S,head);
        printf("删除成功！");
        printf("是否继续删除电影：1为是0为退出:\n");
        scanf("%d",&xz);
    }

    printf("----------------以下是电影信息----------------\n");
    if(IsEmpty(head))
        printf("无电影信息！\n");
    else{
        current = head;
        while(current!=NULL)
        {
            Item mid;
            mid = current->item;
            printf("\t电影：%s\t评分:%d\n",mid.Name,mid.rating);
            current = current->next;
        }
    }
    Item X;
    printf("请输入你希望查找的电影名称：\n");
    scanf("%s",Input);
    strcpy(X.Name,Input);
//    printf("请输入该电影的评分:\n");
 //   scanf("%d",&X.rating);
    Position P;
    P = (Position)malloc(sizeof(Node));
    P = Find(X,head);
    printf("该电影的评分为:  ");
 //   X = P->item;
    printf("%d",P->item.rating);
    free(P);
    current = head;
    while(current!=NULL)
    {
        free(current);
        current = current->next;
    }
    return 0;

}

int IsEmpty(List L)  //判断列表是否为空
{
    if(L==NULL)
        return 1;
    else
        return 0;
}

int IsLast(Position P,List L) //判断是否为列表的末尾
{
    return P->next == NULL;

}

Position Find(Item X, List L)
{
    Position P;
    P = L;
    while(P!=NULL && strcmp(P->item.Name,X.Name))  //请注意，判断两个字符串是否相等，用strcmp（）函数
        P = P->next;
    return P;
}

Position FindPrevious(Item X,List L)  //寻找到X元素之前的节点
{
    Position P;
    P = L;
    while(P->next!=NULL && strcmp(P->next->item.Name,X.Name))  //请注意，判断两个字符串是否相等，用strcmp（）函数
        P = P->next;
    return P;

}

void Delete(Item X,List L)
{
    Position tecell;
    Position P = FindPrevious(X,L); //X之前的节点
    if(!IsLast(P,L))
    {
        tecell = P->next;
        P->next = tecell->next;
        free(tecell);
    }
}

void insert(Item X, List L, Position P)
{
    Position tell;
    tell = (Position)malloc(sizeof(Node));
    tell->item = X;
    tell->next = P->next;
    P ->next = tell;
}

char * s_gets(char * r, int N)
{
    char * res;
    char * find;
    res = fgets(r,N,stdin);
    if(res)
    {
        find = strchr(r,'\n');
        if(find)
            *find = '\0';
        else{
            while(getchar()!='\n')
                continue;
        }
    }
    return res;
}
