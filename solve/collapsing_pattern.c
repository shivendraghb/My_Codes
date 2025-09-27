#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter value of n: ");
    scanf("%d", &n);
    int size=2*n-1;
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            int top=i-1;
            int bottom=size-i;
            int left=j-1;
            int right=size-j;

            int min_dist=top;
            if(bottom < min_dist)
            min_dist=bottom;
            if(left < min_dist)
            min_dist=left;
            if(right<min_dist)
            min_dist=right;

            printf("%d ",n-min_dist);
        }
        printf("\n");
    }
    return 0;
}
