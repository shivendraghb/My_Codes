#include<stdio.h>
int main()
{
    int a[20],found=0,n,key;
    printf("enter the number of elements in the array(less than 20): ");
    scanf("%d",&n);
    printf("enter the key: ");
    scanf("%d",&key);
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==key)
        {
            printf("the element found at %d\n",mid);
            found=1;
            break;
        }
        else if(key<a[mid])
        high=mid-1;
        else if(key>a[mid])
        low=mid+1;
    }
    if(found==0)
    printf("NOT FOUND\n");
    return 0;
}
