#include<stdio.h>
int main()
{
    int marks[100],sum=0,n;
    printf("enter the number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the marks: ");
        scanf("%d",&marks[i]);
        sum=sum+marks[i];
    }
    float average=(float)sum/n;
    printf("the average of marks %d students is %.2f\n",n,average);
    return 0;
}
