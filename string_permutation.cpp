/*
时间：2018/7/25
作者：楼浩然
功能：字符串全排列
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
set<string>res;   //为了防止元素重复，出现重复排列方式
void pemutation(string & s,int from,int to)    //全排列的递归
{
    if(from == to)
    {
        res.insert(s);
    }
    else
    {
        int i;
        for(i=from ; i<=to ; i++)
        {
            swap(s[i],s[from]);
            pemutation(s,from+1,to);
            swap(s[i],s[from]);
        }
    }
}

int main()
{
    string s;
    cin>>s;
    int len = s.size()-1;
    pemutation(s,0,len);
    auto j = res.begin();
    printf("字符串全排列结果如下：\n");
    for( ; j!=res.end() ; j++)
        cout<<*j<<"\n";
    return 0;
}
