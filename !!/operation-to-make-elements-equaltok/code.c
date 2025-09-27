#include<stdio.h>

void sort(int* arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int minOperations(int* nums, int numsSize, int k) {

    sort(nums,numsSize);
    int equal=1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=k)
        {
            equal=0;
            break;
        }
    }
    if(equal)
    return 0;
    if(nums[numsSize-1]<k)
    return -1;
    int count=0,flag=0;
    for(int i=0;i<numsSize;i++)
    {
       if(nums[i]>k && (i==numsSize-1 || nums[i]!=nums[i+1]))
       {
            flag=1;
            count++;
       }
    }
    return flag?count:-1;
}

int main()
{
    int a[5]={5,2,5,4,5};
    int size=5;
    int k=2;
    int result=minOperations(a,size,k);
    printf("%d\n",result);
    return 0;
}
