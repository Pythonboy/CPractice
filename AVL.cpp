/*
ʱ�䣺2018/7/24
���ߣ�¥��Ȼ
���ƣ�ƽ�������
�������ܣ���������ա����ҡ����ֵ&��Сֵ�����롢ɾ��
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int ElementType;
struct AvlNode
{
    ElementType data;
    int height;
    struct AvlNode * Left, * Right;
};
typedef struct AvlNode * Position;
typedef struct AvlNode * AvlTree;

AvlTree MakeEmpty(AvlTree T)   //���һ����
{
    if(T==NULL)
        return NULL;
    else    //�����㲻ΪNULL
    {
        MakeEmpty(T->Left); //��������
        MakeEmpty(T->Right); //��������
        free(T); //�ͷ��ڴ�
    }
    return NULL;
}

Position Find(ElementType X , AvlTree T)
{
    if(T==NULL)
        return NULL;
    else if(X < T->data)
        return Find(X,T->Left);
    else if(X > T->data)
        return Find(X,T->Right);
    else if(X == T->data)
        return T;
}

Position FindMin(AvlTree T)
{
    if(T == NULL)
        return NULL;
    if(T->Left ==NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(AvlTree T)
{
    if(T==NULL)
        return NULL;
    if(T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

ElementType Retrieve(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->data;
}

AvlTree CreateAvlTree(AvlTree T)
{
    return NULL;
}

static int Height(Position T)
{
    if(T==NULL)
        return 0;
    else
        return T->height;
}

int Max(int a,int b)
{
    return a>b?a:b;
}

static Position SingleRatateWithLeft(Position K2)  //������ת
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->height = Max(Height(K2->Left),Height(K2->Right))+1;
    K1->height = Max(Height(K1->Left),Height(K1->Right))+1;
    return K1;
}

static Position SingleRatateWithRight(Position K2)      //ݯݯ��ת
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->height = Max(Height(K2->Left),Height(K2->Right))+1;
    K1->height = Max(Height(K1->Left),Height(K1->Right))+1;
    return K1;
}

static Position DoubleRatateWithRight(Position K3)    //������ת
{
    K3->Right = SingleRatateWithLeft(K3->Right);
    return SingleRatateWithRight(K3);
}

static Position DoubleRatateWithLeft(Position K3)   //������ת
{
    K3->Left = SingleRatateWithRight(K3->Left);
    return SingleRatateWithLeft(K3);
}

AvlTree Insert(ElementType X,AvlTree T)
{
    if(T == NULL)
    {
        T = (struct AvlNode *)malloc(sizeof(struct AvlNode));
        if(T == NULL)
            printf("�ڴ�������\n");
        else{
            T->data = X;
            T->Left = NULL;
            T->Right = NULL;
            T->height = 0;
        }
    }
    else if (X < T->data)
    {
        T->Left = Insert(X,T->Left);
        if(Height(T->Left) - Height(T->Right) == 2)       //���������
        {
            if( X < T->Left->data)      //������������һ��
                T = SingleRatateWithLeft(T);
            else
                T = DoubleRatateWithLeft(T);
        }
    }
    else if (X > T->data)
    {
        T->Right = Insert(X,T->Right);
        if(Height(T->Right) - Height(T->Left) == 2)     //�ұ�������
        {
            if(X > T->Right->data)    //�ұ����������һ��
                T = SingleRatateWithRight(T);
            else
                T = DoubleRatateWithRight(T);
        }
    }
    T->height = Max(Height(T->Left),Height(T->Right))+1;
    return T;
}

void PreOrderTraversel(AvlTree T)
{
    if(T == NULL)
        return;
    cout<<T->data<<" ";
    PreOrderTraversel(T->Left);
    PreOrderTraversel(T->Right);

}

AvlTree Delete(ElementType X, AvlTree T)
{
    Position TempCell;
    if(T == NULL)
        return NULL;
    else if(X == T->data)
    {
        if(T->Left!=NULL && T->Right!=NULL)
        {
            if(Height(T->Left) > Height(T->Right))
            {
                Position P = FindMax(T->Left);
                T->data = P->data;
                T->Left = Delete(T->data,T->Left);
            }
            else if(Height(T->Right) >= Height(T->Left))
            {
                Position P = FindMin(T->Right);
                T->data = P->data;
                T->Right = Delete(T->data,T->Right);
            }
        }
        else
        {
            if(T->Left != NULL)
            {
                Position P = T;
                T =  T->Left;
                free(P);
            }
            else if(T->Right != NULL)
            {
                Position P = T;
                T = T->Right;
                free(P);
            }
        }
    }
    else if (X < T->data)
    {
        T->Left = Delete(X,T->Left);
        if(Height(T->Right)-Height(T->Left) > 1)
        {
            if(Height(T->Right->Right) > Height(T->Right->Left))
            {
                T = SingleRatateWithRight(T);
            }
            else
            {
                T = DoubleRatateWithRight(T);
            }
        }
        else
        {
            T->height = Max(Height(T->Right),Height(T->Left))+1;
        }
    }
    else if(X > T->data)
    {
        T->Right = Delete(X,T->Right);
        if(Height(T->Left) - Height(T->Right)>1)
        {
            if(Height(T->Left->Left) > Height(T->Left->Right))
            {
                T = SingleRatateWithLeft(T);
            }
            else
            {
                T = DoubleRatateWithLeft(T);
            }
        }
        else
        {
            T->height = Max(Height(T->Left),Height(T->Right))+1;
        }
    }
}

int main()
{
    AvlTree T;
    T = CreateAvlTree(T);
    int i,N;
    cin>>N;
    for(i=0 ; i<N ; i++)
    {
        ElementType temp;
        printf("�������%d������ֵ",i+1);
        cin>>temp;
        T = Insert(temp,T);
    }
    PreOrderTraversel(T);
    /*
    ElementType X;
    printf("\n������ɾ��Ԫ��\n");
    cin>>X;
    T = Delete(X,T);
    cout<<"\n";
    PreOrderTraversel(T);*/
    return 0;
}
