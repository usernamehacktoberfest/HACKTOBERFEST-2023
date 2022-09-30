#include<stdio.h>
int main()
{
	int n;
	int arr[30],count=0;
	printf("Enter the size :");
	scanf("%d",&n);
    int i;
    printf("Enter the values:\n");
    for(i=0;i<n;i++)
    {
    	printf("arr[%d] : ",i);
    	scanf("%d",&arr[i]);
	}
	printf("\n-----------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	int max=arr[0];
	int min=arr[0];
	
	for(i=0;i<n;i++)          // 1 2 3 4 5    0<5 yes max=2;  1<5 2<3 max=3  3<4 max=4 4<5 max=5
	{						// 1<2 max=2
		if(max<=arr[i+1])
		{
			max=arr[i+1];
		}
		
	}
	for(i=1;i<n;i++)
	{
		if(arr[i]<=min)      //3 2 1 4 5    min =3  3<2   010 001
		{
			min=arr[i];
			
		}
	}

	printf("\nMax element of the array is %d ",max);
	printf("\nMin element of the array is %d ",min);
	
}
