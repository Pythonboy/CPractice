//模板一：
性质
并查集算法（union_find sets）不支持分割一个集合,求连通子图、求最小生成树
用法
并查集是由一个数组pre[]，和两个函数构成的，一个函数为find()函数，用于寻找前导点的，第二个函数是join()用于合并路线的
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
    r=pre[r];//找到他的前导结点
    int i=x,j;
    while(i!=r)//路径压缩算法
    {
        j=pre[i];//记录x的前导结点
        pre[i]=r;//将i的前导结点设置为r根节点
        i=j;
    }
    return r;
}

路径压缩为了加快查找的速度，将x点与其根节点直接相连，构造成类似于只有叶子结点而没有分支结点的树

join()函数
void join(int x,int y)
{
    int a=find(x);//x的根节点为a
    int b=find(y);//y的根节点为b
    if(a!=b)//如果a,b不是相同的根节点，则说明ab不是连通的
    {
        pre[a]=b;//我们将ab相连 将a的前导结点设置为b
    }
}

初始化
我们将每一个结点的前导结点设置为自己，如果在join函数时未能形成连通，将独立成点

for(int i=0;i<n;i++)//n表示输入的结点的个数
{
    pre[i]=i;//将每一个结点的前导点设置为自己

}

//例子
#include<iostream>
using namespace std;
 
int  pre[1050];
bool t[1050];               //t 用于标记独立块的根结点
 
int Find(int x)
{
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	
	int i=x,j;
	while(pre[i]!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}
 
void mix(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)
	{
		pre[fy]=fx;
	}
} 
 
int main()
{
	int N,M,a,b,i,j,ans;
	while(scanf("%d%d",&N,&M)&&N)
	{
		for(i=1;i<=N;i++)          //初始化 
			pre[i]=i;
		
		for(i=1;i<=M;i++)          //吸收并整理数据 
		{
			scanf("%d%d",&a,&b);
			mix(a,b);
		}
		
		
		memset(t,0,sizeof(t));
		for(i=1;i<=N;i++)          //标记根结点
		{
			t[Find(i)]=1;
		}
		for(ans=0,i=1;i<=N;i++)
			if(t[i])
				ans++;
				
		printf("%d\n",ans-1);
		
	}
	return 0;
}//dellaserss

