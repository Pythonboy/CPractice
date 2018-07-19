#include<stdio.h>
#include<stdlib.h>
#define MAXNODE 20
typedef char ELemType;
typedef struct SCNode{  //孩子结点 
    int childnode;
    struct SCNode *nextchild;
}CNode;

typedef struct{                      //表头结构 
    ELemType data;
    CNode *firstchid;
    int r;                           //根的位置
}CTBox;

typedef struct{          
    CTBox tree[MAXNODE];
    int n;                           //结点数目 
}CTree;

void InitCtree(CTree &t)
{//初始化树 
    int i;
    printf("请输入树的结点个数：\n");
    scanf("\n%d",&t.n);
    printf("依次输入各个结点：\n"); 
    for(i=0; i<t.n; i++)
    {
      fflush(stdin);
      t.tree[i].data = getchar();
      t.tree[i].r = 0;
      t.tree[i].firstchid = NULL; 
    }
}

void AddChild(CTree &t)
{//添加孩子
    int i,j,k;
    printf("添加孩子\n");           
    for(k=0; k<t.n-1; k++)
    {
      fflush(stdin); 
      printf("请输入孩子结点及其双亲结点的序号:\n");
      scanf("%d,%d",&i,&j); 
      fflush(stdin);
      CNode *p = (CNode *)malloc(sizeof(CNode));
      p->childnode = i;
      p->nextchild = NULL;

      t.tree[i].r = j;                   //找到双亲 

      if(!t.tree[j].firstchid)
          t.tree[j].firstchid = p;
      else
       {
         CNode *temp = t.tree[j].firstchid;
         while(temp->nextchild)
          temp = temp->nextchild;
        temp->nextchild = p;
       }
    }
}

void FindChild(CTree &t)
{//查找孩子结点 
  int i,n;
  printf("\n请输入要查询的结点的序号\n");
  scanf("%d",&n); 
  if(!t.tree[n].firstchid)
   printf("结点 %c 无孩子结点\n",t.tree[n].data);
  else
  {
    CNode *p = t.tree[n].firstchid;
    printf("%c 结点的孩子序号为: \n",t.tree[i].data);
    while(p)
    {
        printf("%d ",p->childnode); 
        p = p->nextchild;
    }
  }
}

void FindParent(CTree &t)
{//查找双亲结点 
  int i,n;
  printf("\n请输入要查询的结点的序号\n");
  scanf("%d",&n); 
  if(!n)                //根结点无双亲 
   printf("结点 %c 无双亲结\n",t.tree[n].data);
  else
   printf("结点 %c 的双亲结点为 %c\n",t.tree[n].data,t.tree[t.tree[n].r].data); 
}

int main()
{
    CTree t;
    InitCtree(t);
    AddChild(t);
    FindChild(t);
    //FindParent(t);
    return 0;
}
