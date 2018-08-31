/*
给定一个图，图中任意两点的距离已知，请你把这个图的所有的点分成两个子集，要求两个子集之间的所有点的距离和最大。对于图中的每一个点，我们可
以设一个数组，用0和1表示属于哪个子集。
*/

void backtrack(int x,int sum) 
{  
    int temp;
    if(x>n) 
    {  
        if(sum>ans) ans=sum; 
        return; 
    } 
    //不选
    set[x]=0;
    temp=0;
    for(int i=1;i<=x;i++) 
    { 
        if(!set[i]) continue;
        temp+=graph[i][x];
    } 
    backtrack(x+1,sum+temp); 
    //选
    set[x]=1;
    temp=0; 
    for(int i=1;i<=x;i++) 
    { 
        if(set[i]) continue; 
        temp+=graph[i][x];
    }   
    backtrack(x+1,sum+temp);   
}

int graph[25][25]; 
int set[25]; 
int ans,n;
int main() 
{  
    cin>>n;  
    for(int i=1;i<=n;i++) 
    { 
        for(int j=1;j<=n;j++) 
        { 
            cin>>graph[i][j];  
        } 
    }   
    backtrack(1,0); 
    cout<<ans<<endl;
}
