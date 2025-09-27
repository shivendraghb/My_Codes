#include<stdio.h>
void sum_difference(int a,int b,int* sum,int* diff)
{
    *sum=a+b;
    *diff=a-b;
}
int main()
{
    int a,b,sum,diff;
    printf("enter the value for a and b: ");
    scanf("%d %d",&a,&b);
    sum_difference(a,b,&sum,&diff);
    printf("sum=%d and difference=%d\n",sum,diff);
    return 0;
}
