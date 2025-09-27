#include<stdio.h>
int main()
{
    int n,x,y,z;
    do
    {
        printf("enter the vale for n: ");
        scanf("%d",&n);
    }while(n < 1 || n > 100);
    while(n > 0)
    {
        do
        {
            scanf("%d %d %d",&x,&y,&z);
        }while(x < 1 || x > 100 || y < 1 || y > 100 || z < 1 || z > 100);

        //here if z-x is <than 0 then we should convert -ve int +ve and same for z-y
        int distA = z-x;
        int distB = z-y;

        if( (z - x) < 0)
        distA = -distA;

        if( (z - y) < 0)
        distB = -distB;

        if(distA < distB)
        printf("Cat A\n");

        else if( distB < distA)
        printf("Cat B\n");

        else
        printf("Mouse C\n");

        n=n-1;
    }
    return 0;
}
