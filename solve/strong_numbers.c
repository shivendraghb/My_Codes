#include<stdio.h>
int main()
{
    int a,rem,sum,fact,n;
    printf("enter the number: ");
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
    {
        n=i;
        sum=0;
        while(n>0)
        {
            rem=n%10;
            fact=1;
            for(int p=1;p<=rem;p++)
            {
                fact=fact*p;
            }
            sum=sum+fact;
            n/=10;
        }
        if(sum==i)
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}
