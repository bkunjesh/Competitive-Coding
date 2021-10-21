#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<char> sum(vector<char> b,vector<char> a)
{ vector<char> c(51);
int sum='0';
c[0]='0';
cout<<"y"<<endl;
    for(int i=a.size()-1;i>=0;i--)
    {
        //cout<<"y"<<endl;
        sum=a[i]-'0'+b[i]-'0'+c[0]-'0';
        c[i+1]=(sum%10)-'0';
        c[0]=(sum/10)-'0';
    }
return c;

}


int main() {
   int t,i,j;
   cin>>t;
   vector<char> a(5),d;
   d.assign(5,'0');

   for(int a0=0;a0<t;a0++)
   {
   	   for(j=0;j<5;j++)
       cin>>a[j];
       for(j=0;j<5;j++)
       cout<<d[j];
       //cout<<d;
       d=sum(d,a);
   }   
   
   for(int i=0;i<10;i++)
   cout<<d[i];
    return 0;
}

