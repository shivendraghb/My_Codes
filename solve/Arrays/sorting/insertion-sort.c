#include<stdio.h>
int main()
{
    int a[20],n;
    printf("enetr the number of elements in the array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element: ");
        scanf("%d",&a[i]);
    }
    //assume first element is sorted
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int j,current=a[i];
            for(j=i-1;j>=0;j--)
            {
                a[j+1]=a[j];
                if(j==0||a[j-1]<=current)
                break;
            }
            a[j]=current;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
