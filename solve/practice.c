#include <stdio.h>
int main()
{
	int arr[]={1,-1,2,4,6,8,16,12,19,-20};
	int i;
	int max=arr[0];
	int min=arr[0];

	for(i=0;i<10;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
		if(arr[i]>max)
		{
			max=arr[i];
		}
    }
	printf("max: %d \n min: %d",max,min);
	return 0;
}
