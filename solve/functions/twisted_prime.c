#include<stdio.h>
int prime(int n)
{
    int temp=n;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
        if(count==2)
        {
            int rev=0,rem;
            while(n>0)
            {
                rem=n%10;
                rev=rev*10+rem;
                n/=10;
            }
            if(rev==temp)
            return 1;
            else
            {
                return 0;
            }
        }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    if(prime(n))
    {
        printf("twisted prime number\n");
    }
    else
    printf("not twisted prime\n");
    return 0;
}
