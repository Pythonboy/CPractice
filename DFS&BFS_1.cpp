/*
时间：2018/7/22
作者：楼浩然
功能：二叉树的深度优先搜索和广度优先搜索
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode * Left;
    struct TreeNode * Right;
};

typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree CreateTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert(int X,SearchTree T)
{
    if(T==NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        T->val = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    if(X < T->val)
        T->Left = Insert(X,T->Left);
    else if(X>T->val)
        T->Right = Insert(X,T->Right);
    return T;
}

int main()
{
    int N;
    printf("请输入元素个数：\n");
    cin>>N;
    int i,temp;
    SearchTree T;
    T = CreateTree(T);
    for(i=0 ; i<N ; i++)
    {
        printf("请输入第%d个元素：",i+1);
        cin>>temp;
        T = Insert(temp,T);
    }
    printf("\n广度优先搜索结果如下:\n");
    queue<SearchTree>BFS;
    BFS.push(T);
    while(!BFS.empty())
    {
        SearchTree Node = BFS.front();
        BFS.pop();
        if(Node)
        {
            cout<<Node->val<<" ";
            BFS.push(Node->Left);
            BFS.push(Node->Right);
        }
    }
    printf("\n深度优先搜索结果如下：\n");
    stack<SearchTree>DFS;
    DFS.push(T);
    while(!DFS.empty())
    {
        SearchTree Node = DFS.top();
        DFS.pop();
        if(Node)
        {
            cout<<Node->val<<" ";
            DFS.push(Node->Right);
            DFS.push(Node->Left);
        }
    }
    return 0;
}
