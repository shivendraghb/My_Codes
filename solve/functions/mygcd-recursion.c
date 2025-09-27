#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int gcd(int n1,int n2,int i,int count)
{
    if(i>n1||i>n2)
        return count;
    else
    {
        if(n1%i==0&&n2%i==0)
            {
                count=i;
            }
        return gcd(n1,n2,i+1,count);
    }

}

int main()
{
    int t,n1,n2;
    printf("enter the number of test cases: ");
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("enter the numbers: ");
        scanf("%d %d",&n1,&n2);
        int result=gcd(n1,n2,1,0);
        printf("gcd=%d\n",result);
    }

    return 0;
}
