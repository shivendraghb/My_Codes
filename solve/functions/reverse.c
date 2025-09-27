#include<stdio.h>
int reverse(int n)
{
    int rem,rev=0;
    while(n>0)
    {
        rem=n%10;
        rev=10*rev+rem;
        n/=10;
    }
    return rev;
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=reverse(n);
    printf("the reverse of the given number is:%d\n",result);
    return 0;
}
