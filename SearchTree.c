/*
时间：2018/6/26 15点11分
作者：楼浩然
功能：二叉查找树
1.创建一个查找二叉树
2.判断一个二叉树是否为空
3.清空查找二叉树
4/查找二叉树中的某一元素。返回该节点
5.查找二叉树中的最大值，返回该节点
6.查找二叉树中的最小值，返回该节点
7.将元素添加入二叉树中
8.删除二叉树中的一个元素
9.取出二叉树中某一个节点的元素值
*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

int IsEmpty(SearchTree T);
SearchTree CreateSearchTree(SearchTree T);  //创建查找二叉树
SearchTree MakeEmpty(SearchTree T);  //将树清空
Position Find(ElementType X,SearchTree T); //查找树中的某一个元素
Position FindMin(SearchTree T);//寻找树中的最小值
Position FindMax(SearchTree T); //寻找树中的最大值
SearchTree Insert(ElementType X,SearchTree T);//将元素插入树中
SearchTree Delete(ElementType X,SearchTree T);//将树中的某一元素删除
ElementType Retrieve(Position P); //取出P节点的元素

struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

int main(void)
{
    SearchTree T;
    T = NULL;
    int Y;
    int i;
    /*
    T = Insert(10,T);
    T = Insert(11,T);
    T = Insert(12,T);
    T = Insert(13,T);
    T = Insert(9,T);
    T = Insert(4,T);*/
    for(i=0 ; i<10 ; i++)
    {
        printf("请往查找二叉树中添加元素：\n");
        scanf("%d",&Y);
        T = Insert(Y,T);
    }

    Position P;
    P = FindMin(T);
    printf("二叉查找树中的最小值是%d\n",Retrieve(P));
    P = FindMax(T);
    printf("二叉查找树中的最大值是%d\n",Retrieve(P));
    ElementType X;
    X = Retrieve(P);
    T = Delete(X,T);
    P = FindMax(T);
    printf("此时二叉查找树中的最大值是%d\n",Retrieve(P));
    X = 12;
    P = Find(X,T);
    if(P)
        printf("元素%d的位置已查到\n",P->Element);
    else
        printf("查找二叉树中不含元素%d\n",X);
    X = 13;
    P = Find(X,T);
    if(P)
        printf("元素%d的位置已查到\n",P->Element);
    else
        printf("查找二叉树中不含元素%d\n",X);
    T = MakeEmpty(T);
    if(IsEmpty(T))
        printf("二叉树已被清空\n");
    else
        printf("清空函数失败，二叉树未被清空\n");
    return 0;

}
int IsEmpty(SearchTree T)
{
    if(T==NULL)
        return 1;
    else
        return 0;
}
SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}
SearchTree MakeEmpty(SearchTree T)      //递归释放内存
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X,SearchTree T)   //递归查找。二叉树的结构保证了对于每个节点X，左子树中的所有关键子都小于X的关键字值，右子树则大于
{
    if(T==NULL)
        return NULL;
    else if(X < T->Element)
        return Find(X,T->Left);
    else if(X > T->Element)
        return Find(X,T->Right);
    else
        return T;
}


Position FindMin(SearchTree T)  //也是递归查找
{
    if(T == NULL)
        return NULL;
    else if(T->Left== NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)  //递归实现
{
    if(T == NULL)
        return NULL;
    else if(T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}
/*
Position FindMax(SearchTree T)  //非递归实现方式
{
    if( T == NULL)
        return T;
    else
    {
        while(T->Right != NULL)
            T = T->Right;
    }
    return T;
}
*/


SearchTree Insert(ElementType X,SearchTree T)   //依然是递归实现
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T==NULL)
            printf("内存不足\n");
        else{
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if(X < T->Element)
    {
        T->Left = Insert(X,T->Left);
    }
    else if(X > T->Element)
    {
        T->Right = Insert(X,T->Right);
    }
    return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
    Position TemCell;
    if(T == NULL)
        printf("没有发现元素\n");
    else if(X < T->Element)
        T->Left = Delete(X,T->Left);
    else if(X > T->Element)
        T->Right = Delete(X,T->Right);
    else if(T->Left && T->Right)
    {
        TemCell = FindMin(T->Right);
        T->Element = TemCell->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else
    {
        TemCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TemCell);
    }
    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}
