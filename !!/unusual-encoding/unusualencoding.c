#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int hammingdistance(int a,int b)
{
    int xor=a^b;
    int distance=0;
    while(xor)
    {
        distance+=xor&1;
        xor>>=1;
    }
    return distance;
}
int main()
{
    int a,b;
    printf("enter the two numbers: ");
    scanf("%d %d",&a,&b);
    int result=hammingdistance(a,b);
    printf("hamming distance=%d\n",result);
    return 0;
}
