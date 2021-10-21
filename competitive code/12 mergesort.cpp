#include<iostream>
#include<vector>

using namespace std;
merge(vector<int> v,int l,int mid,int h)
{
    //i=l,j=mid+1;
	vector<int> left;
	vector<int> right;
	for(int p=l;p<mid+1;p++)
	{
		left.push_back(v[p]);
	}
	for(int q=mid+1;q<=h;q++)
	{
		right.push_back(v[q]);
	}
	
	//i=l,h,j=mid
	int i=0,j=0;
	while(i<=mid-l+1&&j<=h-mid)
	{
		if(left[i]<right[j])
		{
			v.push_back(left[i++]);
		}
		else
		v.push_back(right[j++]);
	}
	while(i<=mid-l+1)
	v.push_back(left[i++]);
	while(j<=h-mid)
	v.push_back(right[j++]);
	
}

mergesort(vector<int> v,int* l,int* h)
{
	int* mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(v,l,mid);
		mergesort(v,mid+1,h);
		merge(v,l,mid,h);
		
	}
}

int main()
{
	vector<int> v;
	v[0]=4;
	v[1]=2;
	v[2]=9;
	v[3]=6;
	
	mergesort(v,v.begin(),v.end());
	for(int i=0;i<4;i++)
	cout<<v[i];
}
