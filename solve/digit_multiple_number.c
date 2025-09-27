#include<stdio.h>
int main()
{
    int n,rem=0,temp;
    do
    {
        printf("enter the number: ");
        scanf("%d",&n);
    }while(n<10);
    temp=n;
    while(n>0)
    {
        rem=n%10;
        n/=10;
    }
    if(temp%rem==0)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
