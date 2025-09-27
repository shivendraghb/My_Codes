//binary to hexadecimal
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
        rem=n%10000;
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
        if(rem==1000)
        x=8;
        if(rem==1001)
        x=9;
        if(rem==1010)
        x=A;
        if(rem==1011)
        x=B;
        if(rem==1100)
        x=C;
        if(rem==1101)
        x=D;
        if(rem==1110)
        x=E;
        if(rem==1111)
        x=F;
        y=x*pow(10,i);
        sum=sum+y;
        i++;
        n/=10000;
    }
    printf("the binary number %d in hexadecimal is %d",temp,sum);
    return 0;
}
