#include<stdio.h>
#define long long ll;
int main()
{
    int n;
    printf("enter the number n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        int c=1;
        for(int j=1;j<=i;j++)
        {
            printf("%d ",c);
            c=c*(i-j)/j;
        }
        printf("\n");
    }
    return 0;
}
