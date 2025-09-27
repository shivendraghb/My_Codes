#include <stdio.h>
int main()
{
    int n,sum=0;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        sum=sum+i;
    }
    if(sum==n)
    printf("perfect number\n");
    else
    printf("not a perfect number\n");
    return 0;
}
