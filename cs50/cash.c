#include<stdio.h>
int main()
{
    int n,count=0;
    do
    {
        printf("enter the amount of change owed: ");
        scanf("%d",&n);
    }while(n<0);
    while(n>=25)
    {
        n=n-25;
        count++;
    }
    while(n>=10)
    {
        n=n-10;
        count++;
    }
    while(n>=5)
    {
        n=n-5;
        count++;
    }
    while(n>=1)
    {
        n=n-1;
        count++;
    }
    printf("%d\n",count);
    return 0;
}
