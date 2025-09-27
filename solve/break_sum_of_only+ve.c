#include<stdio.h>
int main()
{
    int n,sum=0;
    for(int i=0;i<=5;i++)
    {
        printf("enter the number: ");
        scanf("%d",&n);
        if(n<0)
        break;
        sum=sum+n;
    }
    printf("sum=%d",sum);
    printf("\n");
    return 0;
}
