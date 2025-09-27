#include<stdio.h>
int main()
{
    int n;
    printf("enter the value of n: ");
    scanf("%d",&n);
    for(int row=1;row<=n;row++)
    {
        for(int column=1;column<=n-row;column++)
        {
            printf(" ");
        }
        for(int column=1;column<=row;column++)
        {
            printf("%c",'A'+row+column-2);
        }
        printf("\n");
    }
    return 0;
}
