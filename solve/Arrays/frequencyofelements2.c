#include<stdio.h>
int main()
{
    int a[]={1,1,3,5,2,2,2,5,6,4,4,0,6,9,9,7,7};
    int n=sizeof(a)/sizeof(a[0]);
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        count++;
        else
        {
            printf("%d is repeating %d times\n",a[i],count);
            count=1;
        }
    }
    return 0;
}
