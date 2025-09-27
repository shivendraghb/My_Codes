#include<stdio.h>
//example of non-tail recursion
//LIFO
int fact(int n)
{
    if (n==0)
    return 1;
    else
    return (n*fact(n-1));
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=fact(n);
    printf("factorial=%d\n",result);
    return 0;
}
