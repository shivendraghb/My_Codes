#include<stdio.h>
#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int compare(const void* a, const void* b)
 {
     int num1 = *(int*)a;
     int num2 = *(int*)b;
     return (num1 > num2) - (num1 < num2);
 }
 int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
     *returnSize=1;
     for(int i=2;i<=numsSize;i++)
     {
         *returnSize *= i;
     }

     *returnColumnSizes=(int*)malloc(*returnSize * sizeof(int));
     int** result=(int**)malloc(*returnSize * sizeof(int*));
     for(int i=0;i< *returnSize;i++)
     {
         (*returnColumnSizes)[i]=numsSize;
         result[i]=(int*)malloc(numsSize*sizeof(int));
     }

     qsort(nums, numsSize, sizeof(int), compare);
     for(int j=0;j<numsSize;j++)
     {
         result[0][j]=nums[j];
     }
     int index=1;
     while(index < *returnSize)
     {
         int i=numsSize-2;
         while(i>=0 && nums[i]>=nums[i+1])
         i--;
         if(i<0)
         break;
         int j=numsSize-1;
         while(nums[j]<=nums[i])
         j--;

         int temp=nums[i];
         nums[i]=nums[j];
         nums[j]=temp;

         for(int start=i+1,end=numsSize-1;start<end;start++,end--)
         {
             temp=nums[start];
             nums[start]=nums[end];
             nums[end]=temp;
         }

         for(int k=0;k<numsSize;k++)
         {
             result[index][k]=nums[k];
         }
         index++;
     }
     return result;
 }
 int main()
 {
    int nums[] = {0, -1, 1, -1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** permutations = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Total permutations: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", permutations[i][j]);
        }
        printf("\n");
        free(permutations[i]);
    }
    free(permutations);
    free(returnColumnSizes);

    return 0;
}
