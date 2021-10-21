#include<iostream>
using namespace std;
class complex
{
	private:
		int real;
		int img;
	public:
    complex(int r=0,int i=0)
    {
    	real=r;
    	img=i;
	}
	complex add(complex x)
	{
		complex temp;
		temp.real=real+x.real;
		temp.img=img+x.img;
		return temp;		
	}
	complex operator+(complex x)
	{
		complex temp;
		temp.real=real+x.real;
		temp.img=img+x.img;
		return temp;		
	}
	complex operator*(complex x)
	{
		complex temp;
		temp.real=real*x.real-img*x.img;
		temp.img=real*x.img+img*x.real;
		return temp;		
	}
	complex conjugate()
	{
		complex temp;
		temp.real=real;
		temp.img=-img;
		return temp;
	}
	//write a fuction to divide two complex no.
	//.....
	// for divide operator we have to use concept of
	// friend function(abdul bari 12.3)
	friend complex operator/(complex c1,complex c2)
	{
		complex temp;
		//write fun. for conjugate
		temp=c1*c2.conjugate();
		temp.real/=(c2.real*c2.real+c2.img*c2.img);
		temp.img/=(c2.real*c2.real+c2.img*c2.img);
		return temp;
	}
	void print()
	{
		cout<<real<<" + i"<<img<<endl;
	}
	friend ostream & operator<<(ostream &o,complex &c1)  //INSERTION OPERATOR OVERLOADING
	{
		o<<c1.real<<" + i"<<c1.img<<endl;
		return o;
	}
	//~complex();
};
/*complex::~complex()
{
	cout<<"complex fucked up"<<endl;
}*/
int main()
{
	complex c1(2,3),c2(2,3);
	complex c3(5,6);
	cout<<c3;
	c3=c1.add(c2);
	c3.print();
	c3=c3+c2;
	c3.print();
	c3=c1*c2;
	c3.print();
	c3=c1/c2;
	c3.print();
	cout<<c3;
}
