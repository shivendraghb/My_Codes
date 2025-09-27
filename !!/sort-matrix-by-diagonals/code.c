/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void sort(int* arr,int size,int descending)
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<size-i-1;j++)
            {
                if((descending && arr[j]<arr[j+1]) || (!descending && arr[j]>arr[j+1]))
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
     }

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize=gridSize;
    *returnColumnSizes=(int*)malloc(gridSize*sizeof(int));

    for(int i=0;i<gridSize;i++)
    {
        (*returnColumnSizes)[i]=gridSize;
    }

    int** result=(int**)malloc(gridSize*sizeof(int*));
    for(int i=0;i<gridSize;i++)
    {
        result[i] = (int*)malloc(gridSize * sizeof(int));
        for(int j=0;j<gridSize;j++)
        {
            result[i][j]=grid[i][j];
        }
    }

    for(int row=0;row<gridSize;row++)
    {
        int temp[gridSize],count=0,r=row,c=0;
        while(r<gridSize && c<gridSize)
        {
            temp[count++]=result[r++][c++];
        }
        sort(temp,count,1);
        r=row,c=0,count=0;
        while(r<gridSize && c<gridSize)
        {
            result[r++][c++]=temp[count++];
        }
    }

    for(int column=1;column<gridSize;column++)
    {
        int temp[gridSize],count=0,r=0,c=column;
        while(r<gridSize && c<gridSize)
        {
            temp[count++]=result[r++][c++];
        }
        sort(temp,count,0);
        r=0,c=column,count=0;
        while(r<gridSize && c<gridSize)
        {
            result[r++][c++]=temp[count++];
        }
    }
    return result;
}

int main()
{
    int n;
    printf("enter the size of matrix(nXn): ");
    scanf("%d",&n);

    int** sample=(int**)malloc(n*sizeof(int*));//Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
                                               //Output: [[8,2,3],[9,6,7],[4,5,1]]
    for(int i=0;i<n;i++)
    {
        sample[i]=(int*)malloc(n*sizeof(int));
    }

    printf("enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&sample[i][j]);
        }
    }

    int returnSize;
    int* returnColumnSizes;
    int** answer=sortMatrix(sample,n,NULL,&returnSize,&returnColumnSizes);

    printf("the sorted matrix is:\n");
    for(int i=0;i<returnSize;i++)
    {
        for(int j=0;j<returnColumnSizes[i];j++)
        {
            printf("%d ",answer[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++)
    {
        free(sample[i]);
        free(answer[i]);
    }

    free(sample);
    free(answer);
    free(returnColumnSizes);

    return 0;
}
