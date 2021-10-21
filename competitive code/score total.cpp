#include<iostream>
using namespace std;
int main()
{
    int m,c,p;
    cout<<"what is score of math?"<<endl;
    cin>>m;
    cout<<"what is score of chem.?"<<endl;
    cin>>c;
    cout<<"what is score of phy.?"<<endl;
    cin>>p;
    int z=m+c+p;
    cout<<"hence, your total is :"<<endl<<z<<endl;
    int y=z*100/300;
    cout<<"and your % is:"<<endl<<y<<" %"<<endl;
    
    system("pause");
    return 0;
    
    
    
    }
