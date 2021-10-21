#include<iostream>
using namespace std;

class rectangle
{
	private:
		int length;
		int breadth;
	public:
		rectangle();
		rectangle(int length,int breadth);
		rectangle(rectangle &r);
		int getlength();
		int getbreadth();
		void setlength(int length);
		void setbreadth(int breadth);
		int area();
		int parimeter();
		bool issquare();
	//	~rectangle();		
};
class cuboidal: public rectangle
{
	private:
	 int height;
	public:
		cuboidal(int l=0,int b=0,int h=0)
		{
			height=h;
			setlength(l);
			setbreadth(b);
		}
		int getheight()
		{
			return height;
		}
		void setheight(int h)
		{
			height=h;
		}
		int volume()
		{
			return height*getlength()*getbreadth();
		}	
};
int main()
{
	rectangle r1;
	//r1.setlength(15);
	r1.setbreadth(5);
	cout<<r1.getlength()<<" "<<r1.getbreadth()<<endl;
	cout<<r1.area()<<" "<<r1.parimeter()<<endl;
	if(r1.issquare()) cout<<"square"<<endl;
	else cout<<" not square"<<endl;
	
	cuboidal c1(1,2,3);
	cout<<c1.volume()<<endl;
}
rectangle::rectangle()
{
	length=1,breadth=1;
}
rectangle::rectangle(int l,int b)
{
	length=l,breadth=b;
}
rectangle::rectangle(rectangle &r)
{
	length=r.getlength();
	breadth=r.getbreadth();
}
int rectangle::getlength()
{
	return length;
}
int rectangle::getbreadth()
{
	return breadth;
}
void rectangle::setlength(int l)
{
	length=l;
}
void rectangle::setbreadth(int b)
{
	breadth=b;
}
int rectangle::area()
{
	return length*breadth;
}
int rectangle::parimeter()
{
	return 2*(length+breadth);
}
bool rectangle::issquare()
{
	return length==breadth;
}
/*rectangle::~rectangle()
{
	cout<<"rectangle fucked up"<<endl;
}*/
