
1. lowbit() 函数： 功能就是求某一个数的二进制表示中最低的一位1，举个例子，x = 6，它的二进制为110，那么lowbit(x)就返回2，
因为最后一位1表示2。

（一）
int lowbit(x) 
{   
    return x - (x & (x - 1));
}

（二）
int lowbit(x) 
{   
    return x & -x;
}

2.查询前缀和
int sum(int x, ArrayInt c, int n)
{
    int ret = 0;
    for ( ; x > 0; ret += c[x], x -= lowbit(x));
    return ret;
}

3.更新后缀和
void update(int x, int val, ArrayInt c, int n)
{
    for ( ; x <= n; c[x] += val, x += lowbit(x));
}

注：
update(int x,int v)
其中x为在c数组中的起始位置
v是在数组中更新的值的大小

getsum(int x)
得到的结果是在c数组中从1~x中的值的大小；

举例:
如果是update(i,N[i]];
则getsum(3)是数组N[1],N[2],N[3]的和


用途：
一： 对数组元素进行排序
如果通过 update(N[i],1)
那么 getsum(N[i]) 得到的答案是N[i]在数组中从小到大排序的结果
