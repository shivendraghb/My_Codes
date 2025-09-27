#include<stdio.h>
int fact(int n,int result)
{
    if(n==0)
    return result;
    else
    return fact(n-1,n*result);
}
int main()
{
    int n,result=1;
    printf("enter the number: ");
    scanf("%d",&n);
    int factorial=fact(n,result);
    printf("the factorial is %d\n",factorial);
    return 0;
}
