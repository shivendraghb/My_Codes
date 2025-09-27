#include<stdio.h>
int main()
{
    int a[20],n,swaps=0;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element: ");
        scanf("%d",&a[i]);
    }                     /*here n-1 because first element is being compared with the rest of the array elements so no need to include it*/
    for(int i=0;i<n-1;i++)/*The reason for n-1 is that in each iteration of the outer loop, the largest unsorted element gets moved to its*/
    {                       /*correct position at the end of the array*//*BETTER TO USE THE WORD "PASS"*/
        for(int j=0;j<n-1-i;j++)/*here n-1-i because for each time the outer loop runs the element is compared and is sorted*/
        {                       /*accordingly so next comparison should be done with the remaining elements that are*/
            if(a[j]>a[j+1])     /*n-1-i for each itteration of outer loop*/
            {
                swaps++;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;//5 2 4 10 8 6 7 1 3 9
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d\n",swaps);
    return 0;
}
