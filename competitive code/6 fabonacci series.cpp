#include<iostream>
using namespace std;
int main()
{
	int n=5,a=0,b=1;
	cout<<a<<" "<<b<<" ";
	for(int i=2;i<n;i++)
	{
		int c=a+b;
		cout<<c<<" ";
		a=b;
		b=c;
	}
	
}
