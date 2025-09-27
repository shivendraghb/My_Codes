#include <stdio.h>
#include <math.h>
int main()
{
    int n,i=0;
    printf("enter the binary number which consists of 0 and 1: ");
    scanf("%d",&n);
    int rem,sum=0,y,temp=n;
    while(n>0)
    {
        rem=n%10;
        if(rem!=0&&rem!=1)
        {
            printf("enter a valid number\n");
            return 0;
        }
        else
        {
            y=pow(2,i);
            sum=sum+rem*y;
            n/=10;
            i++;
        }
    }
    printf("the binary number %d is %d\n",temp,sum);
    return 0;
}
