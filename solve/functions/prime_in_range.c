#include<stdio.h>
void print_prime(int a,int b)
{
    for(int i=a;i<=b;i++)
    {
        int count=0;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j==0)
            count++;
        }
        if(count==1)
        printf("%d ",i);
    }
     printf("\n");
}
int main()
{
    int a,b;
    printf("enter the values for a and b: ");
    scanf("%d %d",&a,&b);
    print_prime(a,b);
    return 0;
}
