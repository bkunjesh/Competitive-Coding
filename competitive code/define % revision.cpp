#include<iostream>
#define PER(a,b,c)((a+b+c)*100/300)
using namespace std;
int main()
{
    float a,b,c;
    cout<<"marks in phy?"<<endl;
    cin>>a;
    cout<<"marks in che?"<<endl;
    cin>>b;
    cout<<"marks in math?"<<endl;
    cin>>c;
    int per;
    per=PER(a,b,c);
    cout<<"hence your %  is : "<<per<<endl;
    
    system("pause");
    return 0;

    
    }
