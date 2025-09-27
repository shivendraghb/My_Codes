#include<stdio.h>
void prime(int n)
{
    for(int i=1;i<=n/2;i++)
    {
        int count=0;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j==0)
            count++;
        }
        if(count==1)
        {
            int count1=0;
            for(int j=1;j<=n-i;j++)
            {
                if((n-i)%j==0)
                count1++;
            }
            if(count1==2)
            printf("%d+%d ",i,n-i);
        }
    }
    printf("\n");
}
int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    prime(n);
    return 0;
}
