#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],result[10][10];
    int m,n;
    printf("enter the order of matrix: ");
    scanf("%d %d",&m,&n);
    printf("enter the elements of first matrix: ");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&a[i][j]);
        }
    }
    printf("enter the elements of second matrix: ");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&b[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
