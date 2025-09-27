//binary to octal
#include <stdio.h>
#include <math.h>
int main()
{
    int n,i=0;
    printf("enter the binary number: ");
    scanf("%d",&n);
    int rem,sum=0,x,y,temp=n;
    while(n>0)
    {
        rem=n%1000;
        if(rem!=0&&rem!=1)
        {
            printf("enter a valid number\n");
            return 0;
        }
        else
        {
            if(rem==0)
            x=0;
            if(rem==1)
            x=1;
            if(rem==10)
            x=2;
            if(rem==11)
            x=3;
            if(rem==100)
            x=4;
            if(rem==101)
            x=5;
            if(rem==110)
            x=6;
            if(rem==111)
            x=7;
            y=x*pow(10,i);
            sum=sum+y;
            i++;
            n/=1000;
        }
    }
    printf("the binary number %d in octal is %d\n",temp,sum);
    return 0;
}
