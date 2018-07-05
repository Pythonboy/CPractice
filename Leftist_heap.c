#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode * PriorityQueue;


PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);

#define Insert(X,H) ( H = Insert1((X),H))
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

struct TreeNode{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if(H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right,H2);
        if(H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if(H1 == NULL)
        return H2;
    else if(H2 == NULL)
        return H1;
    if(H1->Element < H2->Element)
        return Merge1(H1,H2);
    else
        return Merge1(H2,H1);
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        printf("Out of space\n");
    else
    {
        SingleNode->Element = X;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode,H);
    }
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue HLeft,HRight;
    if(IsEmpty(H))
    {
        printf("Priority queue is Empty\n");
        return;
    }
    HLeft = H->Left;
    HRight = H->Right;
    free(H);
    return Merge(HLeft,HRight);
}
