(一）
//根据前序、中序确定后序
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char in[30], pr[30];
void dfs(char *inorder, char *preorder, int len)
{
	if(len == 0) return ;
	int rootIndex = 0;
	for(;rootIndex<len; rootIndex++)
		if(inorder[rootIndex] == *preorder) break;
	dfs(inorder, preorder+1, rootIndex);
	dfs(inorder+rootIndex+1, preorder+rootIndex+1, len-rootIndex-1);
	cout << *preorder;
}
int main()
{
	while(scanf("%s%s", pr,in) !=EOF)
	{
		dfs(in, pr, strlen(in));
		puts("");
	}
}

（二）
//根据前序、中序确定后序
//首先创建一个二叉树，根据二叉树来后序遍历
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>

using namespace std;

int Q[105];//存放前序遍历
int Z[105];//存放中序遍历

struct TreeNode{  //树节点
	int data;
	TreeNode *l,*r;
};

TreeNode * Tranlate (int fro,int mid,int len){   //把前序和中序遍历结果转换为二叉树
	if(len == 0)return NULL;

	TreeNode *node = new TreeNode;
	node->data = Q[fro];
	int tlen = 0;
	while(1){
		if(Z[mid+tlen] == Q[fro])break;
		++tlen;
	}
	node->l = Tranlate(fro+1,mid,tlen);
	node->r = Tranlate(fro+tlen+1,mid+tlen+1,len - tlen - 1);

	return node;
}
void BackP(TreeNode const *head){   //进行后序遍历并输出
	if(head == NULL)return ;

	BackP(head->l);
	BackP(head->r);
	printf("%d ",head->data);//注意这里的输出格式，这里最后一个数后也有空格。（贼坑）
}

int main(){
	int N,i;
	while(scanf("%d",&N)!=EOF){
		for(i=0 ; i<N ; i++)scanf("%d",&Z[i]);
		for(i=0 ; i<N ; i++)scanf("%d",&Q[i]);
		TreeNode *head = Tranlate(0,0,N);
		BackP(head);
		printf("\n");
	}
	return 0;
}


（三）
#include <iostream>
using namespace std;

void BinaryTreeFromInOrderAndPreOrderToPostOrder(char InOrder[],char PreOrder[],int length)
{
    if(length<=0){
        return;
    }
    int rootIndex=0;
    for(;rootIndex<length;rootIndex++){
        if(InOrder[rootIndex]==PreOrder[0])
            break;
    }
    BinaryTreeFromInOrderAndPreOrderToPostOrder(InOrder,PreOrder+1,rootIndex);
    BinaryTreeFromInOrderAndPreOrderToPostOrder(InOrder+rootIndex+1,PreOrder+rootIndex+1,length-rootIndex-1);
    cout<<PreOrder[0];
}

void BinaryTreeFromInOrderAndPostOrderToPreOrder(char InOrder[],char PostOrder[],int length)
{
    if(length<=0){
        return ;
    }
    int rootIndex=0;
    for(;rootIndex<length;rootIndex++){
        if(InOrder[rootIndex]==PostOrder[length-1])
            break;
    }
    cout<<PostOrder[length-1];
    BinaryTreeFromInOrderAndPostOrderToPreOrder(InOrder,PostOrder,rootIndex);
    BinaryTreeFromInOrderAndPostOrderToPreOrder(InOrder+rootIndex+1,PostOrder+rootIndex,length-rootIndex-1);
}

int main(int argc,char* argv[])
{
    char pre[]="GDAFEMHZ";
    char in[]="ADEFGHMZ";
    char post[]="AEFDHZMG";
    cout<<"The original strings are:\n";
    cout<<"Pre:"<<pre<<endl
        <<"In:"<<in<<endl
        <<"Post:"<<post<<endl;

    cout<<"From InOrder And PreOrder To PostOrder:\n";
    BinaryTreeFromInOrderAndPreOrderToPostOrder(in,pre,8);
    cout<<endl;
    cout<<"From InOrder And PostOrder To PreOrder:\n";
    BinaryTreeFromInOrderAndPostOrderToPreOrder(in,post,8);
    cout<<endl;
    return 0;
}


























