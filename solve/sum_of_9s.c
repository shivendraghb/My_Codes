#include<stdio.h>
#include<math.h>
int main()
{
    int N,i,n,sum=0;
    printf("enter the value of N: ");
    scanf("%d",&N);
    n=N;
    for(i=1;i<=N;i++)
    {
        int m;
        m=pow(10,n)-1;
        n=n-1;
        sum=sum+m;
    }
    printf("sum=%d",sum);
    return 0;
}

