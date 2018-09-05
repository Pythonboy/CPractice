



//暴力求解
string findLongestPalindrome(string &s)
{
    int length=s.size();//字符串长度
    int maxlength=0;//最长回文字符串长度
    int start;//最长回文字符串起始地址
    for(int i=0;i<length;i++)//起始地址
        for(int j=i+1;j<length;j++)//结束地址
        {
            int tmp1,tmp2;
            for(tmp1=i,tmp2=j;tmp1<tmp2;tmp1++,tmp2--)//判断是不是回文
            {
                if(s.at(tmp1)!=s.at(tmp2))
                    break;
            }
            if(tmp1>=tmp2&&j-i>maxlength)
            {
                maxlength=j-i+1;
                start=i;
            }
        }
        if(maxlength>0)
            return s.substr(start,maxlength);//求子串
        return NULL;
}


//DP
string findLongestPalindrome(string &s)
{
    const int length=s.size();
    int maxlength=0;
    int start;
    bool P[50][50]={false};
    for(int i=0;i<length;i++)//初始化准备
    {
        P[i][i]=true;
        if(i<length-1&&s.at(i)==s.at(i+1))
        {
            P[i][i+1]=true;
            start=i;
            maxlength=2;
        }
    }
    for(int len=3;len<=length;len++)//子串长度
        for(int i=0;i<=length-len;i++)//子串起始地址
        {
            int j=i+len-1;//子串结束地址
            if(P[i+1][j-1]&&s.at(i)==s.at(j))
            {
                P[i][j]=true;
                maxlength=len;
                start=i;
            }
        }
    if(maxlength>=2)
        return s.substr(start,maxlength);
    return NULL;
}
