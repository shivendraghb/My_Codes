#include<stdio.h>
int jumpingonclouds(int c_count, int* c, int k) {
int energy=100;
for(int i=0;;)
{
    i=(i+k)%c_count;
    energy--;
    if(c[i]==1)
    energy-=2;
    if(i==0)
    break;
}
return energy;
}
int main()
{
    int k;
    int c[]={0,0,1,0,0,1,1,0};
    int c_count=sizeof(c)/sizeof(c[0]);
    printf("enter the jump distance: ");
    scanf("%d",&k);
    int result=jumpingonclouds(c_count,&c[0],k);
    printf("energy remaining=%d\n",result);
    return 0;
}
