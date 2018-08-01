#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
vector<int>Book;

void DFS_stack(int st,int n) //�ǵݹ�������ȱ���
{
    stack<int>Res; //ʹ��ջʵ��
    int i;
    for(i=1 ; i<=n ; i++)
        Book[i] = 0;
    Res.push(st);
    Book[st] = 1;
    while(!Res.empty())
    {
        int node = Res.top();
        cout<<node<<" ";
        Res.pop();
        for(i=1 ; i<=n ; i++)
        {
            if(Graph[node][i]==1 && !Book[i])
            {
                Res.push(i);
                Book[i] = 1;
            }

        }
    }
}

int main()
{
    printf("�����붥�������ͱ�����:\n");
    int N,K,i,j,k;
    scanf("%d %d",&N,&K);
    Book.resize(N+1);
    memset(Graph,0,sizeof(Graph));
    printf("�����������:\n");
    for(i=0 ; i<K ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    DFS_stack(1,N);
    return 0;
}
