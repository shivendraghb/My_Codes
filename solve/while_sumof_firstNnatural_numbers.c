#include<stdio.h>
int main()
{
    int n,m=1,sum=0;
    printf("enter terms: ");
    scanf("%d",&n);
    while(m<=n)
    {
        sum=sum+m;
        m=m+1;
    }
    printf("the sum of first %d terms is %d\n",n,sum);
    return 0;
}
