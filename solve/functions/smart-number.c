#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void check_smart(int t)
{
    for(int i=1;i<=t;i++)
    {
        int n,count=0;
        printf("enter the number: ");
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            if(n%j==0)
                count++;
        }
        if(count%2!=0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
int main()
{
    int t;
    printf("enter the number of test cases: ");
    scanf("%d",&t);
    check_smart(t);
    return 0;
}
