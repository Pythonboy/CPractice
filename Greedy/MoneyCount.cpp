/*
这个问题在我们的日常生活中就更加普遍了。假设1元、2元、5元、10元、20元、50元、100元的纸币分别有c0, c1, c2, c3, c4, c5, c6张。现在要
用这些钱来支付K元，至少要用多少张纸币？用贪心算法的思想，很显然，每一步尽可能用面值大的纸币即可。在日常生活中我们自然而然也是这么做的。
在程序中已经事先将Value按照从小到大的顺序排好。
*/

#include<iostream>  
#include<algorithm>  
using namespace std;  
const int N=7;   
int Count[N]={3,0,2,1,0,3,5};  
int Value[N]={1,2,5,10,20,50,100};  
    
int solve(int money)   
{  
    int num=0;  
    for(int i=N-1;i>=0;i–)   
    {  
        int c=min(money/Value[i],Count[i]);  
        money=money-c*Value[i];  
        num+=c;  
    }  
    if(money>0) num=-1;  
    return num;  
}  
   
int main()   
{  
    int money;  
    cin>>money;  
    int res=solve(money);  
    if(res!=-1) cout<<res<<endl;  
    else cout<<“NO”<<endl;  
}  
