#include<stdio.h>
#include<math.h>
int main()
{
    int n,x,num=0;
    printf("enter the digits for packing: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("enter the %d position digit: ",i);
        scanf("%d",&x);
        num=x*pow(10,i-1)+num;
    }
    printf("the number is %d\n",num);
    return 0;
}
