#include<stdio.h>
void christmas_tree(int spaces,int hash);
int main()
{
    int n,temp;
    printf("enter the height of christmas tree: ");
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
    for(int i=1;i<=n;i++)
    {
        christmas_tree(n-i,i);
    }
    temp=temp-1;
    }
    for (int i=1;i<=n;i++)
    {
        printf("   ");
        printf("#");
        printf("\n");
    }
    return 0;
}
    void christmas_tree(int spaces , int hash)
{
    for (int i = 1; i <=spaces; i++)
    {
        printf(" ");
    }

    for (int i = 1; i < 2*hash; i++)
    {
        printf("#");
    }
    printf("\n");
}
