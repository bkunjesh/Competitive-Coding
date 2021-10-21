#include<stdio.h>
int binarysearch(int a[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		return mid;
		else if(a[mid]>x)
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
}
int main()
{
	int a[]={2,4,6,8};
	int x;
	scanf("%d",&x);
	int i=binarysearch(a,4,x);
	if(i!=-1)
	printf("%d is at index %d",x,i);
	else
	printf("no not found ");
	
	
}
