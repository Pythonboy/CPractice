/*
这是《算法导论》上的例子，也是一个非常经典的问题。有n个需要在同一天使用同一个教室的活动a1,a2,…,an，教室同一时刻只能由一个活动使用。
每个活动ai都有一个开始时间si和结束时间fi 。一旦被选择后，活动ai就占据半开时间区间[si,fi)。如果[si,fi]和[sj,fj]互不重叠，ai和aj两个
活动就可以被安排在这一天。该问题就是要安排这些活动使得尽量多的活动能不冲突的举行。例如下图所示的活动集合S，其中各项活动按照结束时间单
调递增排序。
*/
#include<cstdio>  
#include<iostream>   
#include<algorithm>   
using namespace std;      
int N;  
struct Act  
{  
    int start;  
    int end;  
}act[100010];  
  
bool cmp(Act a,Act b)    
{    
    return a.end<b.end;    
}   
  
int greedy_activity_selector()    
{    
    int num=1,i=1;     
    for(int j=2;j<=N;j++)    
    {    
        if(act[j].start>=act[i].end)    
        {    
            i=j;    
            num++;    
        }    
    }    
    return num;  
}  
  
int main()    
{    
    int t;  
    scanf(”%d”,&t);  
    while(t–)  
    {  
        scanf(”%d”,&N);  
        for(int i=1;i<=N;i++)  
        {  
            scanf(”%lld %lld”,&act[i].start,&act[i].end);  
        }  
        act[0].start=-1;   //这一步很有意思
        act[0].end=-1;  
        sort(act+1,act+N+1,cmp);   
        int res=greedy_activity_selector();  
        cout<<res<<endl;    
    }  
} 
