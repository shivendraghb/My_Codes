#include<stdio.h>
int main()
{
    int a[]={4,5,4,8,12,6},found=0;
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
        }
    }
    if(found==0)
    printf("key not found\n");
    return 0;
}
