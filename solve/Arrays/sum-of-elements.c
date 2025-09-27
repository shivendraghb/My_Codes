#include<stdio.h>
int find_sum(int a,int sum)
{
    return sum+a;
}
int main()
{
    int n,element[100],sum=0;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&element[i]);
    }
    for(int i=0;i<n;i++)
    {
        sum=find_sum(element[i],sum);
    }
    printf("sum=%d\n",sum);
    return 0;
}
