#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
    long int t,n,i,j,m,element,min;
    vector<long int> a,cpy;
     cin>>t;
     while(t--)
    {
       min=1000000000;   //min ka kuchh karna he usko maxdena he initially.
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>element;
            a.push_back(element);
            cpy.push_back(element);
            //cout<<a[i]<<" ";
        }
        sort(cpy.begin(),cpy.end());
        /*for(auto p=cpy.begin();p<cpy.end();p++)
        cout<<*p<<" ";*/
        vector<long int>::iterator it1,it2;
        for(int i=m-1;i<n;i++)
        {
            //check for same color
             it1=find (a.begin(),a.end(),cpy[i]);
             it2=find (a.begin(),a.end(),cpy[i-m+1]);
             //cout<<(it1-it2)%m<<" ";
            if((it1-it2)%m!=0)
            {
                //cout<<cpy[i]<<" "<<cpy[i-m+1]<<" "<<min<<endl;
                //cout<<cpy[i]-cpy[i-m+1]<<" ";
                if(min>(cpy[i]-cpy[i-m+1]))
                 min=cpy[i]-cpy[i-m+1];
                 
            }
            
        }
        cout<<min<<endl;
        a.clear();
        cpy.clear();
    }    

    return 0;
}
