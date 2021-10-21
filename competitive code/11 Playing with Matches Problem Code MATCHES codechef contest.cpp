#include<iostream>
using namespace std;
int matchstick(int a)
{
	if(a==1)
	return 2;
	if(a==2)
	return 5;
	if(a==3)
	return 5;
	if(a==4)
	return 4;
	if(a==5)
	return 5;
	if(a==6)
	return 6;
	if(a==7)
	return 3;
	if(a==8)
	return 7;
	if(a==9)
	return 6;
	if(a==0)
	return 6;
}
int main()
{
	int test,A,B,sum,t,S;
	cin>>test;
	for(int i=0;i<test;i++)
  {
	S=0;
	cin>>A;
	cin>>B;
	sum=A+B;
	while(sum!=0)
	{
		t=sum%10;
		S+=matchstick(t);
		sum=sum/10;
	}
	cout<<S<<endl;
  }
}
