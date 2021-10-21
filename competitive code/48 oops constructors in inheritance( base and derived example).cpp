#include<iostream>
using namespace std;
class base
{
	public:
		base()
		{
			cout<<"default of base"<<endl;
		}
		base(int x)
		{
			cout<<"param. of base "<<x<<endl;
		}
};
class derived:public base
{
	public:
		derived()
		{
			cout<<"default of derived"<<endl;
		}
		derived(int a)
		{
			cout<<"param. of derived "<<a<<endl;
		}
		derived(int x,int a):base(x)
		{
			cout<<"param. of derived "<<a<<endl;
		}
};
int main()
{
	//derived d1;
	//derived d1(3);
	derived d1(3,4);
	
}
