#include<stdio.h>
int main()
{
    int a[]={4,5,3,10,2};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                printf("for value %d NGE is %d\n",a[i],a[j]);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("for value %d NGE is %d\n",a[i],-1);
        }
    }
    return 0;
}
