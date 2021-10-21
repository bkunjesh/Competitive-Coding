#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main()
{     int t;
     cin>>t;
     while(t--)
    {
        long int i,n,k,element,tpsum=0;
        vector<long int> a;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>element;
           a.push_back(element);
           //cout<<element<<endl;
        }
        
        for(i=0;i<n;i++)
        {
             tpsum+=a[i];
            //cout<<tpsum<<" ";
            if(tpsum<k*(i+1))
            break;
        }
        if(i==n)
        cout<<"YES"<<endl;
        else
        cout<<"NO "<<i+1<<endl;
        a.clear();
    }   

    return 0;
}
