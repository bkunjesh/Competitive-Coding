#include<stdio.h>
void merge(int a[],int l,int m,int h)
{
	int i,j;
	int n1=m-l+1,n2=h-m;
	int left[n1],right[n2];
	int x=0,y=0,z=l;
	for(i=0;i<n1;i++) left[i]=a[i+l];
	for(j=0;j<n2;j++) right[j]=a[m+1+j];
	
	while(x<n1&&y<n2)
	{
		if(left[x]>=right[y]) a[z++]=right[y++];
		else
		a[z++]=left[x++];
	 } 
	 
	 while(x<n1)
	 a[z++]=left[x++];
	 while(y<n2)
	 a[z++]=right[y++];
	 
}
void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int m=(h+l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

int main()
{
	int a[]={12,33,43,55,333,77,65,32};
	int i=0,j=7;
	mergesort(a,i,j);
	for(int p=0;p<8;p++)
	{
		printf("%d ",a[p]);
	}
}
