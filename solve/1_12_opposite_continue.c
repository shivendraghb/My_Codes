#include<stdio.h>
int main()
{
    int n;
    printf("enter the number of rows: ");
    scanf("%d",&n);
    for(int row=1;row<=n;row++)
    {
        for(int column=1;column<=row;column++)
        {
            printf("%d ",column);
        }
        printf("\n");
    }
    for(int row=1;row<=n-1;row++)
    {
        for(int column=1;column<=n-row;column++)
        {
            printf("%d ",column);
        }
        printf("\n");
    }
    return 0;
}
