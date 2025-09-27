#include<stdio.h>
int main()
{
    int n,rem,count=0,i=1,temp;
    printf("enter the number to unpack: ");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
       rem=n%10;
       printf("the number at %d position is: %d\n",i,rem);
       count++;
       i++;
       n/=10;
    }
    printf("total number of digits in %d are: %d\n",temp,count);
    return 0;
}
