#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
bool map[100][100];//记录图形
bool visited[100];//记录点是不是已经被访问过了
bool del[100];//记录点是不是已经删除了
int dfn[100];//记录点访问的次序
stack<int>s1,s2;
int dotn;
void init()
{
    int line;
    cin>>dotn>>line;
    for(int i=1;i<=line;i++)
    {
        int u,v;
        cin>>u>>v;
        map[u][v]=1;
    }
    memset(visited,0,sizeof(visited));
    memset(del,0,sizeof(del));
}
void dfs(int u,int &time)
{
    visited[u]=1;
    dfn[u]=++time;
    s1.push(u);
    s2.push(u);
    for(int i=1;i<=dotn;i++)
    {
        if(map[u][i])
        {
            if(!visited[i])
            {
                dfs(i,time);
            }
            else
            {
                if(!del[i])
                {
                    while(dfn[s2.top()]>dfn[i])s2.pop();//注意这个地方
                }
            }
        }
    }
    if(u==s2.top())
    {
        while(u!=s1.top())
        {
            cout<<s1.top()<<"   ";
            del[s1.top()]=1;
            s1.pop();
        }
        cout<<u<<endl;
        del[s1.top()]=1;
        s1.pop();
        s2.pop();
    }
}
void Gadow()
{
    init();
    int time=0;
    for(int i=1;i<=dotn;i++)
    {
        if(!visited[i])
        {
            dfs(i,time);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    Gadow();
    return 0;
}
