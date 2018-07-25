/*
时间：2018/7/25
作者：楼浩然
功能：字符串循环左移N位，要求时间复杂度O(N),空间复杂度O(1);
原理： （X^y^)^ = YX;
例如：X=ab,X^=ba;Y=cde,Y^=edc;(X^Y^)^=(baedc)^=cdeab;
*/

#include <iostream>
#include <string>
using namespace std;

void Reverse_string(string &s,int from,int to)
{
    char ch;
    while(from < to)
    {
        ch = s[from];
        s[from++] = s[to];
        s[to--] = ch;
    }
}

void String_move(string &s,int N)
{
    int len = s.size();
    Reverse_string(s,0,N-1);
    Reverse_string(s,N,len-1);
    Reverse_string(s,0,len-1);
}

int main()
{
    string s;
    cin>>s;
    String_move(s,4);
    cout<<s;
    return 0;
}

