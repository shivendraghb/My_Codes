#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,rem,sum=0,count,n;
    printf("enter the range: ");
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;i++)
    {
        n=i;
        count=0,sum=0;
        while(n>0)
        {
            n/=10;
            count++;
        }
        n=i;
        while(n>0)
        {
            rem=n%10;
            sum=sum+pow(rem,count);
            n/=10;
        }
        if(sum==i)
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}
