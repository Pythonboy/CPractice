/*
时间：2018/7/19
作者：楼浩然
功能：KPM算法求字符串的模式匹配
*/
#include <iostream>
#include <string>
using namespace std;

void Next(int *next,string pattern)
{
    int i = -1;
    int j = 0;
    next[j] = i;
    while(j < pattern.size()-1)
    {
        if(i==-1 || pattern[j]==pattern[i])
        {
            next[++j] = ++i;
        }
        else
        {
            i = next[i];
        }
    }
}

int KMP(string target,string pattern)
{
    int len = pattern.size();
    int next[len];
    Next(next,pattern);
    if(target!="" && pattern!="" && pattern.size() < target.size())
    {
        int start = 0;
        int cnt = next[start];
        while(target.size() - start + cnt >= pattern.size())
        {
            if(cnt == -1 || target[start] == pattern[cnt])
            {
                start++;
                cnt++;
            }
            else
            {
                cnt = next[cnt];
            }
            if ( cnt == pattern.size())
                return start - cnt;
        }
    }
    return -1;
}

int main()
{
    string a,b;
    cout<<"请输入字符串target:\n";
    cin>>a;
    cout<<"请输入字符串pattern:\n";
    cin>>b;
    int res = KMP(a,b);
    cout<<res;
    return 0;
}















他山之玉：
（一）
public int[] next(String pattern){
        int i = -1;
        int j = 0;
        int[] next = new int[pattern.length()];
        next[0] = -1;
        while(j < pattern.length() - 1){
            if(i == -1 || pattern.charAt(i) == pattern.charAt(j)){
                i++;
                j++;
                next[j] = i;
            }else{
                i = -1;
            }
        }
        return next;
    }
    
public int kmp(String target,String pattern){
        if(target != null && pattern != null && target.length() > pattern.length()){
            int start = 0;
            int[] next = next(pattern);
            int count = next[start];
            while(target.length() - start + count >= pattern.length()){
                if(count == -1 || target.charAt(start) == pattern.charAt(count)){
                    count ++;
                    start ++;
                }else{
                    //这里就是核心了，如果next[count] <= 0 目标字符串直接从当前的下一个开始比较。
                    //因为等于-1的话说明是在匹配第一个字符串，当前匹配失败，不可能再与pattern第一个字符匹配了，当然是要继续匹配下一个，如果是0的话，说明是在匹配第一个与pattern头相同的串或者匹配与pattern头无关的字符，匹配失败，当然也是继续匹配下一个字符串。
                    count = next[count];
                }
                
                if(count == pattern.length()){
                    return start - count;
                }
            }
        }
        return -1;
    }
作者：senninha
链接：https://www.jianshu.com/p/f28de6e3edf4
來源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。


（二）
public static int[] getNext(String ps) { 
      char[] p = ps.toCharArray();  
      int[] next = new int[p.length]; 
      next[0] = -1;  
      int j = 0; 
      int k = -1;
      while (j < p.length - 1) {
        if (k == -1 || p[j] == p[k]) {
            next[++j] = ++k;
        } else {
            k = next[k]; 
        } 
     }
     return next； 
 }
