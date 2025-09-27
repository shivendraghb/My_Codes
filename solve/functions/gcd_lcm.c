#include<stdio.h>
void find_gcd_lcm(int a,int b)
{
    int gcd,lcm;
    for(int i=1;i<=a&&i<=b;i++)
    {
        if(a%i==0&&b%i==0)
        {
            gcd=i;
        }
    }
    lcm=(a*b)/gcd;
    printf("gcd=%d and lcm=%d\n",gcd,lcm);
}
int main()
{
    int a,b;
    printf("enter the values for a and b: ");
    scanf("%d %d",&a,&b);
    find_gcd_lcm(a,b);
    return 0;
}
