#include<iostream>
using  namespace std;
int main()
{
	for(int i=0;i<5;i++)
	{
		if(i<3)
		{
			for(int j=1+i;j>0;j--)
		   {
			cout<<"*";
		   }
		   cout<<endl;					
		}
		else
		{
			for(int j=0;j<5-i;j++)
			cout<<"*";
			cout<<endl;
		}
	}
	
}
