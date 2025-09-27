#include <stdio.h>

int main()
{
    int a[]={1,2,3,10,4,5,6};
    int n=sizeof(a)/sizeof(a[0]),pos;
    printf("enter the position to be deleted: ");
    scanf("%d",&pos);
    //update the array
    pos=pos-1;
    for(int i=pos;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    //print updated array
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
