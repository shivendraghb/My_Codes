#include <stdio.h>
#include<math.h>
int main()
{
    int n,rem,sum=0;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=0;n>0;i++)
    {
        rem=n%10;
        if(rem==0)
        rem=1;
        else if(rem==1)
        rem=0;
        sum=rem*pow(10,i)+sum;
        n/=10;
    }
    printf("%d\n",sum);
    return 0;
}
