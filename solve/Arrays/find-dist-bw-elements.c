#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[]={1,3,4,5,4,1,14,57};
    int n=sizeof(a)/sizeof(a[0]);
    int dist,dist1=0,dist2=0;
    int num1=5,num2=57;
    for(int i=0;i<n;i++)
    {
        if(a[i]==num1)
        {
            dist1=i;
            if(dist2!=0)
            {
               dist=abs(dist1-dist2);
            }
        }
        if(a[i]==num2)
        {
            dist2=i;
            if(dist1!=0)
            {
                dist=abs(dist2-dist1);
            }
        }
    }
    printf("the distance between the numbers is: %d\n",dist);
    return 0;
}
