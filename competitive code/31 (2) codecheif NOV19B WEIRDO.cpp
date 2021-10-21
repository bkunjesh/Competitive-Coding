#include <iostream>
//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/math/constants/constants.hpp>
using namespace std;

//using boost::multiprecision::cpp_dec_float_50;
#include<bits/stdc++.h>
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
//template<typename T>
//inline T ans()
bool check1(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    else return false ;
}
bool check(string s)
{
    ll count=0,i;
    for(i=1;i<s.size();i++)
    {   if(!check1(s[i])){
         if(i>1 && !check1(char(s[i-2]))) break;
         if(!check1(char(s[i-1]))) break;
    }
    }
    if(i==s.size()) return true;
    else return false;
   
}
int main() {
ll t,l,i,j;
cin>>t;
while(t--)
{
    long double sa=1,sb=1;
   
    cout<<std::fixed;
    cout<<std::setprecision(7);
    ll at[26]={0};
    ll bt[26]={0};
    ll a[26]={0};
    ll b[26]={0};
    ll alice=0,bob=0;
    cin>>l;
   // cout<<l<<endl;
    string s[l];
    f(i,l)
    {
        cin>>s[i];
       
    }
   
    f(i,l)
    {
          if(check(s[i]))
        { // Alicew
     //  cout<<"yes";
         f(j,s[i].size())
         {
           //  cout<<s[i]<<" "<<s[i]-'a'<<" "<<at[i]<<endl;
             at[s[i][j]-'a']++;
         }
         for(char c='a';c<='z';c++)
         {
             size_t found = s[i].find(c);
    if (found != string::npos)   a[c-'a']+=1;
         }
         alice++;
        }
        else {
            //BOB
           // cout<<"no";
             f(j,s[i].size())
         {
            // cout<<s[i]<<" "<<s[i]-'a'<<" "<<bt[i]<<endl;
             bt[s[i][j]-'a']++;
         }
         for(char c='a';c<='z';c++)
         {
             
             size_t found = s[i].find(c);
    if (found != string::npos) b[c-'a']+=1;
         }
         bob++;
        }
    }
     f(i,26)
         {
           //  cout<<at[i]<<" "<<bt[i]<<endl;
             // cout<<a[i]<<" "<<b[i]<<endl;
             if(a[i]!=0) sa=sa+log(a[i])-alice*log(at[i]);
                if(b[i]!=0) sb=sb+log(b[i])-bob*log(bt[i]);
         }
   
    if((exp(sa-sb))>pow(10,7)) cout<<"Infinity"<<endl;
    else  cout<<exp(sa-sb)<<endl;
}


return 0;
}
