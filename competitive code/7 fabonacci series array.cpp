#include<iostream>
using namespace std;
int main()
{
	int n,a[100];
	cin>>n;
	a[0]=0;
	a[1]=1;
	cout<<a[0]<<" "<<a[1]<<" ";
	for(int i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		cout<<a[i]<<" ";
		a[i-2]=a[i-1];
		a[i-1]=a[i];
	}
	
}
