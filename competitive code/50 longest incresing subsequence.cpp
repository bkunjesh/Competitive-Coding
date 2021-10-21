#include<iostream>
using namespace std;
int lis(int a[],int n)
{
	int l[n];
	for(int i=0;i<n;i++) l[i]=1;
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	{
		if(a[i]>a[j])
		{
			if(l[j]+1>l[i])
			l[i]=l[j]+1;
		}
	}
	int max=1;
	for(int i=0;i<n;i++)
	{
		//cout<<l[i]<<" ";
		if(l[i]>max)
	    max=l[i];
		
	}
	
	return max;
}
int main()
{
	int a[7]={1,3,6,1,3,8,9};
	cout<<lis(a,7)<<" "<<sizeof(a)/sizeof(a[0]);
}
