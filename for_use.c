/*
时间：2018年6月2日 10点27分
目的： 1）求1-100之间奇数之和
       2）求1-100之间奇数的个数
       3）求1-100之间偶数之和
       4）求1-100之间奇数的平均数
作者：少年人
*/

#include <stdio.h>

int main(void){
    int odd_num = 0; //奇数个数
    int odd_sum = 0;  //奇数和
    int odd_mean = 0;  //奇数的平均值
    int even_sum = 0; //偶数的和
    int i;
    for (i = 1; i <= 100; i++)    //1-100以内
    {
        if (i%2==0){     //判断是否为偶数
            even_sum += i;
        }
        else{
            odd_num += 1;
            odd_sum += i;
        }
    }
    odd_mean = odd_sum / odd_num;
    printf("1-100以内奇数的个数：%d\n",odd_num);
    printf("1-100以内奇数的和：%d\n",odd_sum);
    printf("1-100以内奇数的平均值：%d\n",odd_mean);
    printf("1-100以内偶数的和：%d\n",even_sum);
    return 0;
}

/*
输出结果：
1-100以内奇数的个数：50
1-100以内奇数的和：2500
1-100以内奇数的平均值：50
1-100以内偶数的和：2550
*/
