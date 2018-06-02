/*
时间： 2018/6/2 23点39分
作者： 少年人
名称： 一元二次方程
功能： 用户输入一元二次方程的三个参数，求出解
*/

#include<stdio.h>
#include<math.h>

int main(void){
    double a,b,c;
    double x1,x2;
    double theta;
    char ch;
    do{
        printf("请输入一元二次方程的参数a.b.c:\n");
        printf("a=");
        scanf("%lf",&a);  //输入a的值
        printf("b=");
        scanf("%lf",&b);    //输入b的值
        printf("c=");
        scanf("%lf",&c);    //输入c的值
        theta = sqrt(pow(b,2) - 4*a*c) ;    //是否存在解的判定条件
        if (theta>0){
            x1 = (-b+sqrt(theta))/2*a;
            x2 = (-b-sqrt(theta))/2*a;
            printf("x1 = %lf\nx2 = %lf\n",x1,x2);    //两个解
        }
        else if (theta == 0){
            x1 = x2 = (-b)/2*a;
            printf("x1 = x2 = %lf\n",x1,x2);  //一个解
        }
        else{
            printf("No solution\n");      //没有解
        }
        printf("是否继续进行运算：Y/N\n");
        scanf(" %c",&ch);      //用户决定是否继续运算
        } while (ch == 'Y'  || ch == 'y') ;     //循环的判定条件
    return 0;
}

/*
输出结果：
=====================================
a=1
b=2
c=1
x1 = x2 = -1.000000
是否继续进行运算：Y/N
y
请输入一元二次方程的参数a.b.c:
a=1
b=3
c=5
No solution
是否继续进行运算：Y/N
y
请输入一元二次方程的参数a.b.c:
a=4
b=1
c=0
x1 = 0.000000
x2 = -4.000000
是否继续进行运算：Y/N
N
==================================
*/
