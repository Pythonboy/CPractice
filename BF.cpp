/*
时间：2018/7/19
作者：楼浩然
功能：字符串的匹配，判断字符串b是否为字符串a的子串
*/

#include <iostream>
#include <string>
using namespace std;

bool BoyFriend(string a,string b)
{
    int len_a = a.size(), len_b = b.size();
    int i,j;
    int key = 1;
    for(i=0 ; i<=len_a-len_b ; i++)
    {
        int k = i;
        int flag = 1;
        for(j=0 ; j<len_b ; j++)
        {
            if(a[k++]!=b[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            key = 0;
            break;
        }
        else
            continue;
    }
    if(key)
        return false;
    else
        return true;
}

int main()
{
    string a;
    string b;
    cout<<"请输入字符串a:\n";
    cin>>a;
    cout<<"请输入字符串b:\n";
    cin>>b;
    if(BoyFriend(a,b))
        cout<<"字符串"<<b<<"是"<<a<<"的子串\n";
    else
        cout<<"字符串"<<b<<"不是"<<a<<"的子串\n";
    return 0;
}
