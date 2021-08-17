
// Program 3
#include <stdio.h>

class Base {
public:
	int x;
};

//class Derived : Base { }; // is equilalent to class Derived : private Base {}
struct Derived : Base { }; // is equilalent to struct Derived : public Base {}

int main()
{
Derived d;
d.x = 20; // compiler error becuase inheritance is private
getchar();
return 0;
}

