#include <stdio.h>
void Duplicates(int arr[],int n)
{
    int k=0;
    for (int i = 0; i < n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[k]=arr[i];
            k++;
        }
    }
    printf("Array after removing duplicates: ");
    for(int i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Duplicates(arr, n);
    return 0;
}
