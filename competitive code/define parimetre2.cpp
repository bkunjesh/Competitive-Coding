#include<iostream>
#define PARIMETER(a,b)(2*a+2*b)
using namespace std;
int main()
{
    int a1,a2,parimeter;
    parimeter=PARIMETER(a1,a2);
    cout<<"enter the valuof first dimension:" <<endl;
    cin>>a1;
    cout<<"enter the value of second dimention:"<<endl;
    cin>>a2;
    cout<<parimeter;
    system("pause");
    return 0;
    
    
    }


