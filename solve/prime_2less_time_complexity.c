#include<stdio.h>
#include<math.h>
int main()
{
    int n,count=0;
    printf("enter the number: ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("the number %d is not a prime number\n",n);
        return 0;
    }
    if(n%2==0)
    {
        printf("the number %d is even and not a prime\n",n);
        return 0;
    }
    for (int i=3;i<=sqrt(n);i=i+2)
    {
        if(n%i==0)
        {
        count++;
        }
    }
        if(count==0)
        {
            printf("the number %d is a prime number\n",n);
        }
        else
        {
            printf("the number %d is not a prime number\n",n);
        }

return 0;
}
