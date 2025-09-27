#include<stdio.h>
int main()
{
    int n;
    printf("enter th evalue of n: ");
    scanf("%d",&n);
    for(int row=1;row<=n;row++)
    {
        for(int space=1;space<=n-row;space++)
        {
            printf(" ");
        }
        for(int column=1;column<=row;column++)
        {
            printf("%d",1+row+column-2);
        }
        int num=2*(row-1);
        for(int column=1;column<=row-1;column++)
        {
            printf("%d",num);
            num--;
        }
        printf("\n");
    }
    return 0;
}
