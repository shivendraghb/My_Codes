int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
bool nextPermutation(int nums[], int numsSize)
    {
        int i=numsSize-2;
        while(i>=0 && nums[i]>=nums[i+1])
        i--;
        if(i<0)
        return false;
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
        return true;
    }
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if(numsSize<=0)
    return NULL;

    *returnSize=1;
    for(int i=2;i<=numsSize;i++)
    {
        *returnSize *= i;
    }

    *returnColumnSizes=(int*)malloc(*returnSize * sizeof(int));
    if(!*returnColumnSizes) return NULL;
    for(int i=0;i< *returnSize;i++)
    {
        (*returnColumnSizes)[i]=numsSize;
    }

    int** result=(int**)malloc(*returnSize * sizeof(int*));
    if(!result) return NULL;
    for(int i=0;i< *returnSize;i++)
    {
        result[i]=(int*)malloc(numsSize*sizeof(int));
        if (!result[i])
        {
            for(int j=0;j<i;j++)
            free(result[j]);

            free(result);
            return NULL;
        }
    }
    qsort(nums, numsSize, sizeof(int), compare);
    for(int j=0;j<numsSize;j++)
    {
        result[0][j]=nums[j];
    }
    int index=1;
    do
    {
        if(index < *returnSize)
        {
            for(int k=0;k<numsSize;k++)
            {
                result[index][k]=nums[k];
            }
            index++;
        }
    }while(nextPermutation(nums,numsSize));

    return result;
}
