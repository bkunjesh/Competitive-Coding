#include<iostream>
#include<bits/stdc++.h> 
using namespace std;\
int partition(int *a,int start,int end)
{
	int pivot=a[end];
	int pindex=start;     //setpartition index as start initially
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)    //swap if element is lesser than pivot
		{
			swap(a[i],a[pindex]);
			pindex++;
		}
	}
	swap(a[end],a[pindex]);   //swap pivot with element at partition index
	return pindex;
}
void quicksort(int *a,int start,int end)
{
	if(start<end)
	{
		int pindex=partition(a,start,end);   //calling partition
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);	
	}	
}

int main()
{
	int n;
	cin>>n;
	int a[n];	                                                            
	for(int i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<"  ";
	
}
