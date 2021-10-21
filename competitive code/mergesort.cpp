#include<stdio.h>
void merge(int a[],int l,int m,int h)
{
//	int i=0,j=0;
	int left[m-l+1],right[h-m];
	for(int i=0;i<m-l+1;i++) left[i]=a[i+l];
	for(int j=0;j<h-m;j++) right[j]=a[m+1+j];
	int x=0,y=0,z=l;
	while(x<m-l+1&&y<(h-m))
	{
		if(left[x]>=right[y]) a[z++]=right[y++];
		else
		a[z++]=left[x++];
	}
	while(x<m-l+1)
	a[z++]=left[x++];
	while(y<(h-m))
	a[z++]=right[y++];
	
	
}

void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);	
	}
}

int main()
{
	int a[]={1,3,2,9,6};
    	int i=0,j=4;
    	mergesort(a,i,j);
	for(int p=0;p<5;p++)
	printf("%d",a[p]);
	printf("\n");
	
}
