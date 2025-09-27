#include<stdio.h>
int main()
{
    int n,a[100],max,min;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element: ");
        scanf("%d",&a[i]);
    }
        max=a[0];
        min=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
        else if(a[i]<min)
        min=a[i];
    }
    printf("%d %d\n",max,min);
    return 0;
}
