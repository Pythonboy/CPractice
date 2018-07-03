#include <stdio.h>
#include <stdlib.h>
#define MinTableSize 9

struct ListNode;
typedef struct ListNode * Position;
struct HashTal;
typedef struct HashTal * HashTable;

HashTable Initialization(int TableSize);
void DestroyHashTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);

struct ListNode{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTal{
    int TableSize;
    List * TheLists;
};

int main(void)
{

}

int IsPrime(int i)
{
    int item = (int)sqrt(i)+1;
    int j;
    if(i<=1)
        return 0;
    else if(i==2 || i==3)
        return 1;
    else if(i%6!=1 && i&6!=5)
        return 0;
    for(j=5 ; j<i ; j+=6)
    {
        if(i%j==0 || i%(j+2)==0)
            return 0;
    }
    return 1;
}

int NextPrime(int m)
{
    int i = m;
    while(!IsPrime(i))
        i++;
    return i;
}

HashTable Initialization(int TableSize)
{
    HashTable H;
    int i;
    if(TableSize < MinTableSize)
    {
        printf("Table size is too small\n");
        return NULL;
    }
    H = malloc(sizeof(struct HashTal));
    if(H==NULL)
        printf("Out of Space\n");
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List)*H->TableSize);
    if(H->TheLists == NULL)
        printf("Out of Space\n");
    for(i=0 ; i<H->TableSize ; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL)
            printf("Out of Space\n");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;

}

int Hash(const char * Key, int TableSize)
{
    unsigned int HashVal = 0;
    while(*Key!='\0')
        HashVal = (HashVal<<5)+*Key++;
    return HashVal;
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    L = H->TheLists[Hash(Key,H->TableSize)];
    P = L->Next;
    while(P != NULL && P->Element != Key)
        P = P->Next;
    return P;

}

void Insert(ElementType Key,HashTable H)
{
    Position Pos,NewCell;
    List L;
    Pos = Find(Key,H);
    if(Pos == NULL)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL)
            printf("Out of Space\n");
        else
        {
            L = H->TheLists[Hash(Key,H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

ElementType Retrieve(Position P)
{
    return P->Element;
}
