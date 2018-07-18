/*
作者：楼浩然
时间：2018/7/18
功能：使用递归实现汉诺塔的移动过程,并记录移动次数
*/

#include <iostream>
#include <cstdio>
using namespace std;

int move(int n,char x,char y,char z)
{
    int res = 0;
    if(n==1)
    {
        printf("%c-->%c\n",x,z);
        res = 1;
    }
    else
    {
        res += move(n-1,x,z,y);
        printf("%c-->%c\n",x,z);
        res += 1;
        res += move(n-1,y,x,z);
    }
    return res;
}

int main()
{
    int N;//最开始的盘子数
    cin>>N;
    char x='X',y='Y',z='Z';
    int res = move(N,x,y,z);
    cout<<"\n"<<res;
    return 0;
}

