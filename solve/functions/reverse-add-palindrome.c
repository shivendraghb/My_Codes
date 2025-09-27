#include<stdio.h>
int palindrome(int n)
{
    int c=1;
    int temp=n;
    int rev=0;
    while(n>0)
    {
       rev=10*rev+(n%10);
       n/=10;
    }
    int sum=rev+temp;
    c++;
    int temp1=sum,rev1=0;
    while(temp1>0)
    {
       rev1=10*rev1+(temp1%10);
       temp1/=10;
    }
    if(sum==rev1)
    return sum;
    else
    return palindrome(sum);
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    int result=palindrome(n);
    printf("the resulting palindrome is %d\n",result);
    return 0;
}
