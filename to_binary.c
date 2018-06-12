#include <stdio.h>

void to_binary(num)
{
    if (num>1)
        to_binary(num/2);
    printf("%d",num%2);
}
int main(void)
{
    int num;
    scanf("%d",&num);
    to_binary(num);
    return 0;
}
