#include<stdio.h>
int find_sum(int n)
{
    if(n==0)
    return 0;
    else
    return (n%10+find_sum(n/10));
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int sum=find_sum(n);
    printf("sum of digits is:%d\n",sum);
    return 0;
}
