/*
时间：2018/6/25 16点56分
作者：楼浩然
功能：利用数组实现队列
1.判断队列是否为空
2.判断队列是否为满
3.创建一个队列，并确定该队列的容积
4.入队操作和出对操作
5.打印队列头部的元素值
6.出对同时打印该元素值
7.清空队列
8.销毁队列
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType * array;
};

typedef struct QueueRecord * Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType x,Queue q);
ElementType Front(Queue q);
void Dequeue (Queue q);
ElementType FrontAndDequeue(Queue q);

int main(void)
{
    printf("-----------队列的基本使用-------------\n\n");
    Queue q = CreateQueue(10);
    printf("-----------判断队列是否为空-----------\n\n");
    if(IsEmpty(q))
        printf("队列是空！\n");
    else
        printf("队列不为空!\n");
    printf("----------往队列中添加元素并查看元素-------------\n\n");
    int i;
    for(i=0 ; i<11 ; i++)
    {
        Enqueue(i,q);
        printf("第%d次添加元素头部元素是:%d\n",i,Front(q));
    }
    printf("-----------判断队列是否满-------------------\n\n");
    if(IsFull(q))
        printf("队列已满\n");
    else
        printf("队列不满\n");
    printf("----------出对-------------------\n");
    printf("出对元素%d\n",FrontAndDequeue(q));
    if(IsFull(q))
        printf("出对不成功\n");
    else
        printf("出对成功\n");
    printf("----------使队列为空-----------\n");
    MakeEmpty(q);
    if(IsEmpty(q))
        printf("队列清空成功\n");
    else
        printf("队列清空不成功\n");
    printf("---------销毁队列------------\n");
    DisposeQueue(q);
    return 0;
}




int IsEmpty(Queue q)
{
    /*
    if(q->Rear == q->Front-1)
        return 1;
    else
        return 0;
        */
    if(q->Size == 0)
        return 1;
    else
        return 0;
}

void MakeEmpty(Queue q)
{
    q->Size = 0;
    q->Front = 1;
    q->Rear = 0;
}

Queue CreateQueue(int MaxElements)
{
    Queue queue = malloc(sizeof(struct QueueRecord));
    queue->array = malloc(sizeof(ElementType)*MaxElements);
    if(queue == NULL || queue->array == NULL)
    {
        printf("内存不足");
    }
    queue->Capacity = MaxElements;
    MakeEmpty(queue);
    return queue;
}

int IsFull(Queue q)
{
    /*
    if(q->size!=0 && q->Front-1 == q->Rear)
        return 1;
    else
        return 0;
        */
    return q->Size == q->Capacity;
}

static int Succ(int value, Queue q)
{
    if(++value == q->Capacity)
        return 0;
    return value;
}

void Enqueue(ElementType x, Queue q)
{
    if(IsFull(q))
        printf("队列已满\n");
    else
    {
        q->Size++;
        q->Rear = Succ(q->Rear,q);
        q->array[q->Rear] = x;
    }
}

ElementType Front(Queue q)
{
    return q->array[q->Front];
}

void Dequeue(Queue q)
{
    if(IsEmpty(q))
        printf("队列已空\n");
    else
    {
        q->Front = Succ(q->Front,q);
        q->Size--;
    }

}

ElementType FrontAndDequeue(Queue q)
{
    ElementType tem;
    if(IsEmpty(q))
        printf("队列已空\n");
    else
    {
        q->Size--;
        tem = q->array[q->Front];
        q->Front = Succ(q->Front,q);
        return tem;
    }
}

void DisposeQueue(Queue q)
{
    free(q->array);
    free(q);
}
