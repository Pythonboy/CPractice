/*
时间：2018/6/2 19点31分
作者：楼浩然
目的：计算某一个日期在某一年中是第几天，练习switch的用法
*/

#include <stdio.h>

int main(void){
    printf("请输入年份(格式如：2007）：\n");
    int year,month,d;
    scanf("%d",&year);
    printf("请输入月份(格式如:1):\n");
    scanf("%d",&month);
    printf("请输入天数(格式如：15)：\n");
    scanf("%d",&d);
    int day = d;
    int sum = 0;
    switch (month){
    case 12:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 11:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=30;
    case 10:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 9:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=30;
    case 8:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 7:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 6:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=30;
    case 5:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 4:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=30;
    case 3:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=31;
    case 2:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            if (year%4 == 0)
                sum+=29;
            else
                sum += 28;
    case 1:
        if (day!=0){
            sum+=day;
            day = 0;
        }
        else
            sum+=30;
    printf("%d-%d-%d是第%d天",year,month,d,sum);
}
}

/*
输出结果：
—----------------------------------
请输入年份(格式如：2007）：
2018
请输入月份(格式如:1):
5
请输入天数(格式如：15)：
19
2018-5-19是第138天
-----------------------------------
*/
