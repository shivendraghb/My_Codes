#include<stdio.h>
#include<math.h>
int main()
{
    int n,count=0;
    printf("enter the number: ");
    scanf("%d",&n);
    if(n==1)
    {
        printf("the number %d is not a prime number",n);
        return 0;
    }
    for (int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
        count++;
        }
    }
        if(count==0)
        {
            printf("the number %d is a prime number",n);
        }
        else
        {
            printf("the number %d is not a prime number",n);
        }

return 0;
}
