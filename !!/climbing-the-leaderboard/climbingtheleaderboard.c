#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
int* result = malloc(player_count * sizeof(int));
int modified_length = 0;
int* modified = malloc(ranked_count * sizeof(int));
modified[modified_length++]=ranked[0];

for (int i=1;i<ranked_count;i++)
{
    if(ranked[i]!=ranked[i-1])
    {
        modified[modified_length++]=ranked[i];
    }
}
int j=modified_length-1;

for(int i=0;i<player_count;i++)
{
    for(;j>=0;j--)
    {
        if(player[i]>=modified[j])
        {
            continue;
        }
        break;
    }
    result[i]=j+2;
}
*result_count = player_count;
free(modified);
return result;
}

int main()
{
    int ranked_count;
    printf("enter the number of scores in ranked array: ");
    scanf("%d",&ranked_count);
    int* ranked=malloc(ranked_count*sizeof(int));
    printf("enter the scores in ranked array(space separated): ");
    for(int i=0;i<ranked_count;i++)
    {
        scanf("%d",&ranked[i]);
    }

    int player_count;
    printf("enter the number of scores by players: ");
    scanf("%d",&player_count);
    int* player=malloc(player_count*sizeof(int));
    printf("enter the scores by player(space separated): ");
    for(int i=0;i<player_count;i++)
    {
        scanf("%d",&player[i]);
    }

    int result_count;
    int* result=climbingLeaderboard(ranked_count,ranked,player_count,player,&result_count);

    printf("Player rankings:\n");
    for (int i = 0; i < result_count; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(ranked);
    free(player);
    free(result);
}
