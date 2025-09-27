#include<stdio.h>
int main()
{
    int n,sum=0;
    for(int i=1;i<=5;i++)
    {
        printf("enter the number: ");
        scanf("%d",&n);
        if(n<0)
        continue;
        sum=sum+n;
    }
    printf("sum=%d\n",sum);
    return 0;
}
