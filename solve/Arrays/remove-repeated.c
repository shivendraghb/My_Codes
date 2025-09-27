#include <stdio.h>
void Duplicates(int arr[],int n)
{
    int arr2[n], k = 0;
    for (int i = 0; i < n; i++)
    {
        int Duplicate = 0;
        for (int j = 0; j < k; j++)
        {
            if (arr[i] == arr2[j])
            {
                Duplicate = 1;
                break;
            }
        }
        if (Duplicate==0)
        {
            arr2[k++] = arr[i];
        }
    }
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr2[i]);
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
