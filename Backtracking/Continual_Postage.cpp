/*
假设国家发行了k种不同面值的邮票，并且规定每张信封上最多只允许贴h张邮票。连续邮资问题要求对于给定的k和h的值，给出邮票面值的最佳设计，
在1张信封上可贴出从邮资1开始，增量为1的最大连续邮资区间。例如，当k=5和h=4时，面值为(1,3,11,15,32)的5种邮票可以贴出邮资的最大连续邮
资区间是1到70。UVA165就是一道这样的典型例题。用stampval来保存各个面值，用maxval来保存当前所有面值能组成的最大连续面值。那么，
stampval[0] 一定等于1，因为1是最小的正整数。相应的，maxval[0]=1*h。接下去就是确定第二个，第三个......第k个邮票的面值了。对于
stampval[i+1]，它的取值范围是stampval[i]+1~maxval[i]+1。 stampval[i]+1是因为这一次取的面值肯定要比上一次的面值大，而这次取的面值
的上限是上次能达到的最大连续面值+1， 是因为如果比这个更大的话， 那么就会出现断层， 即无法组成上次最大面值+1这个数了。 举个例子， 假设
可以贴3张邮票，有3种面值，前面2种面值已经确定为1,2， 能达到的最大连续面值为6， 那么接下去第3种面值的取值范围为3～7。如果取得比7更大的
话会怎样呢？ 动手算下就知道了，假设取8的话， 那么面值为1,2,8，将无法组合出7。直接递归回溯所有情况， 便可知道最大连续值了。
*/

//标记每种取到的钱数 
void mark(int n,int m,int sum)
{  
    if(m>h) return;  
    vis[sum]=true;
    for(int i=1;i<=n;++i) mark(n,m+1,sum+stampval[i]);    
}

void backtrack(int cur)
{  
    if(cur>k)
    {  
        if(maxval[cur-1]>maxstampval)
        {  
            maxstampval=maxval[cur-1];  
            memcpy(ans,stampval,sizeof(stampval));  
        }  
        return;  
    }  
    for(int i=stampval[cur-1]+1;i<=maxval[cur-1]+1;++i)
    {  
        memset(vis,0,sizeof(vis));  
        stampval[cur]=i;  
        mark(cur,0,0);  
        int num=0,j=1;  
        while(vis[j++]) ++num;  
        maxval[cur]=num;  
        backtrack(cur+1);  
    }  
}

#define MAXN 200 
int h,k,ans[MAXN],stampval[MAXN],maxval[MAXN],maxstampval;  
bool vis[MAXN];  
int main()
{   
    while(scanf("%d %d",&h,&k),h+k)
    {  
        maxval[1]=h;  
        stampval[1]=1;  
        maxstampval=-1;  
        backtrack(2);  
        for(int i=1;i<=k;++i) printf("%3d",ans[i]);  
        printf("->%3d\n",maxstampval);  
    }    
}
