#include<iostream>
#define AREA(a,b)(2*(a+b))
using namespace std;
int main()
{   
    int l,b,area;
    
    cout<<"enter the value of l:"<<endl;
    cin>>l;
    cout<<"enter the value of b:"<<endl;
   cin>>b;
    area=AREA(l,b);
    cout<<"hence the area is :"<<area<<endl;
    
    system("pause");
    return 0;
    
    
    }
