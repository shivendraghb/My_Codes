#include <stdio.h>
#include <math.h>

int main()
{
    double x,y;
    int count;
    count=1;
    read:
        printf("enter the value for x: ");
        scanf("%lf",&x);
        if (x<0)
            printf("value is negative\n");
        else
        {
            y=sqrt(x);
            printf("the square root of %.2lf is %.2lf\n",x,y);
        }
        count=count+1;
        if (count<=5)
        goto read;
        printf("end of computation\n");
        return 0;
}


