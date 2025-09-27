#include<stdio.h>
int main()
{
    int n,a[100],even=0,odd=0;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the element: ");
        scanf("%d",&a[i]);
        if(a[i]%2==0)
        even++;
        else
        odd++;
    }
    printf("number of even elements: %d\n",even);
    printf("number of odd elements: %d\n",odd);
    return 0;
}
