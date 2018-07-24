/*
时间：2018/7/24
作者：楼浩然
功能：二叉树根据前序、中序确定后序 ；根据中序、后序确定前序
*/
#include <iostream>
#include <vector>
using namespace std;

void post(vector<int>pre,vector<int>in,int root ,int in_start,int in_end)
{
    if(in_start > in_end)
        return;
    int j = in_start;
    while(j<in_end && in[j]!=pre[root])
        j++;
    post(pre,in,root+1,in_start,j-1);
    post(pre,in,root + (j-in_start)+1,j+1,in_end);      //这里原理是在root上加上左子树的长度
    cout<<pre[root]<<" ";
}


void pre(vector<int>post,vector<int>in,int root ,int in_start,int in_end)
{
    if(in_start > in_end)
        return;
    int j = in_start;
    while(j<in_end && in[j]!=post[root])
        j++;
    cout<<post[root]<<" ";
    pre(post,in,root-(in_end-j)-1,in_start,j-1);
    pre(post,in,root-1,j+1,in_end);
}

int main()
{
    int N;
    cin>>N;
    vector<int>post(N);
    vector<int>in(N);
    int i;
    for(i=0 ; i<N ; i++)
        cin>>post[i];
    for(i=0 ; i<N ; i++)
        cin>>in[i];
    pre(post,in,N-1,0,N-1);
    return 0;
}
