#include <stdio.h>
#include <stdlib.h>

// function to check if any fresh oranges are left
int fresh(int** grid,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            return 1;
        }
    }
    return 0;
}

int rotting(int** grid,int m,int n)
{
    int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                if (i>0 && grid[i-1][j]==1){grid[i-1][j]=3;count=1;}
                if (i<m-1 && grid[i+1][j]==1){grid[i+1][j]=3;count=1;}
                if (j>0 && grid[i][j-1]==1){grid[i][j-1]=3;count=1;}
                if (j<n-1 && grid[i][j+1]==1){grid[i][j+1]=3;count=1;}
            }
        }
    }

    //convert 3 to 2
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==3)
            {
                grid[i][j]=2;
            }
        }
    }
    return count;
}

int orangesRotting(int** grid,int gridSize,int* gridColSize)
{
    int minutes=0;

    while(rotting(grid,gridSize,*gridColSize))
    {
        minutes++;
    }

    return fresh(grid,gridSize,*gridColSize) ? -1:minutes;
}

int main()
{
    int gridArr[3][3]={{2, 1, 1},{1, 1, 0},{0, 1, 1}};

    //dynamically allocate memory for the grid
    int** grid=(int**)malloc(3*sizeof(int*));
    for (int i=0;i<3;i++)
    {
        grid[i]=(int*)malloc(3*sizeof(int));
        for(int j=0;j<3;j++)
        {
            grid[i][j]=gridArr[i][j];
        }
    }

    int gridSize=3;
    int gridColSize=3;

    int result=orangesRotting(grid,gridSize,&gridColSize);
    printf("Minimum minutes to rot all oranges: %d\n",result);

    //free
    for(int i=0;i<3;i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
