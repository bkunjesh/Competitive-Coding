#include<iostream>
using namespace std;
int main()
{
	int i,n;
	//cin>>n;
	n=45;
	for(i=2;i*i<=n;i++)
	{
		//cout<<i;
		if(n%i==0)
		break;
	}
	
	(i*i>n)?(cout<<"prime"):(cout<<"not prime");
	
}
