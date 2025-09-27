#include<stdio.h>
int first_occurence(int a[],int n,int key)
{
   int low=0,high=n-1,mid,result;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==key)
        {
            result=mid;
            high=mid-1;
        }
        else if(key<a[mid])
        high=mid-1;
        else if(key>a[mid])
        low=mid+1;
    }
    return result;
}
int last_occurence(int a[],int n,int key)
{
    int low=0,high=n-1,mid,result;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==key)
        {
            result=mid;
            low=mid+1;
        }
        else if(key<a[mid])
        high=mid-1;
        else if(key>a[mid])
        low=mid+1;
    }
    return result;
}
int main()
{
    int a[]={1,2,2,2,2,3,3,3,4,4,5,5};
    int n=sizeof(a)/sizeof(a[0]);
    int key;
    printf("enter the key: ");
    scanf("%d",&key);
    int first=first_occurence(a,n,key);
    int last=last_occurence(a,n,key);
    printf("key found at: %d\n",first);
    printf("key found at: %d\n",last);
    return 0;
}

