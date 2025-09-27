#include<stdio.h>
int main()
{
    int n,num=1;
    printf("enter the value of rows: ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            //formula of elements of rows of floyd triangle (i*(i-1))/2+j;
            printf("%d ",num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
