#include <stdio.h>
#include <stdlib.h>
#define MinTableSize 9

typedef unsigned int Index
typedef Index Position

struct HashTbl;
typedef struct HashTbl * HashTable;

HashTable Initialization(int TableSize);
void DestroyHashTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P , HashTable H);
HashTable ReHash( HashTable H);

struct HashEntry{
    ElementType Element;
    enum Kind0fEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl{
    int TabelSize;
    Cell * TheCells;
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
    if(TableSize < MinTableSize)
    {
        printf("Table size is too small\n");
        return NULL;
    }
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        printf("Out of Space\n");
    H->TabelSize = NextPrime(TableSize);
    H->TheCells = malloc(sizeof(Cell)*H->TabelSize);
    if(H->TheCells == NULL)
        printf("Out of Space\n");
    for(i=0 ; i<H->TabelSize ; i++)
        H->TheCells[i].info = Empty;
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
    Position CurrentPos;
    int CollisionNum;
    CollisionNum = 0;
    CurrentPos = Hash(Key,H->TabelSize);
    while(H->TheCells[CurrentPos].info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos += 2* ++CollisionNum - 1;
        if(CurrentPos >= H->TabelSize)
            CurrentPos -= H->TabelSize;
    }
    return CurrentPos;

}

void Insert(ElementType Key,HashTable H)
{
    Position Pos;
    Pos = Find(Key , H);
    if(H->TheCells[Pos].info != Legitimate)
    {
        H->TheCells[Pos].info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}
