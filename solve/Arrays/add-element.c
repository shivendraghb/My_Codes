#include <stdio.h>

int main() {
    int a[]={1,2,3,5,6};
    int n=sizeof(a)/sizeof(a[0]),pos,num;
    printf("enter the position to be added: ");
    scanf("%d",&pos);
    printf("enter the number: ");
    scanf("%d",&num);
    n++;
    for(int i=n;i>=pos;i--)
    {
        a[i]=a[i-1];
    }
    a[pos]=num;
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
