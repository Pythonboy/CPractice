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


//他山之玉
public int indexOf(String target,String pattern){
        //判断目标串，匹配串是否满足条件。
        if(pattern != null && target != null && target.length() >= pattern.length()){
            //start指开始匹配的字符起始位置
            int start = 0;
            //count指匹配到的字符数目
            int count = 0;
            //当目标串剩余未匹配的长度大于或等于匹配串串长度，循环继续
            while(target.length() - start >= pattern.length()){
                //满足条件
                if(target.charAt(count + start) == pattern.charAt(count)){              
                    //匹配一个字符后加一。
                    count ++;
                }else{
                        //不满足匹配，count置零，起始匹配位置加一。
                    count = 0;
                    start ++;
                }
                //若count==pattern，说明已经完成了一次匹配。
                if(count == pattern.length()){
                    return start;
                }
            }
        }
        //匹配失败返回-1
        return -1;
    }
作者：senninha
链接：https://www.jianshu.com/p/f28de6e3edf4
來源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
