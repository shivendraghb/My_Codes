#include<stdio.h>
int reverse(int n)
{
    static int rev=0;
    int rem;
    if(n==0)
    return rev;
    else
    {
        rem=n%10;
        rev=10*rev+rem;
        return reverse(n/10);
    }
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=reverse(n);
    printf("the reverse of %d is %d\n",n,result);
    return 0;
}
