#include<stdio.h>
int main()
{
    int a[]={1,2,2,2,2,3,4,4,5,5},found=0;
    int n=sizeof(a)/sizeof(a[0]);
    int key;
    printf("enter the key: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("key found at %d\n",i);
            found++;
            break;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==key)
        {
            printf("key found at %d\n",i);
            found++;
            break;
        }
    }
    if(found==0)
    printf("key not found\n");
    return 0;
}
