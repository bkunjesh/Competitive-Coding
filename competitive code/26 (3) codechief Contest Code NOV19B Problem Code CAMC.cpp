#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
long int isreapting(vector<pair<long int,long int>> cpy,long int i,long int m,long int min)
{
    long int j=i-m+1;
    while((cpy[j]!=cpy[j+1])&&j<i)
    {
        if((cpy[i].second-cpy[j].second)%m!=0)
            {
                //cout<<cpy[i].first<<" "<<cpy[i-m+1].first<<" "<<min<<endl;
                if(min>(cpy[i].first-cpy[j].first)) 
                 min=cpy[i].first-cpy[j].first;
                break; 
            }
            j++;
    }
    return min;
}
int main()
{
    long int t,n,i,m,element,min;
    vector<pair<long int,long int>> cpy;
     cin>>t;
     while(t--)
    {
       min=1000000000;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>element;
            cpy.push_back(make_pair(element,i));
        }
        sort(cpy.begin(),cpy.end());
        vector<long int>::iterator it1,it2;
        for(int i=m-1;i<n;i++)
        {
            if((cpy[i].second-cpy[i-m+1].second)%m!=0)
            {
                //cout<<cpy[i].first<<" "<<cpy[i-m+1].first<<" "<<min<<endl;
                if(min>(cpy[i].first-cpy[i-m+1].first)) 
                 min=cpy[i].first-cpy[i-m+1].first;
            }
            if(cpy[i-m+1].first==cpy[i-m+2].first)
              min=isreapting(cpy,i,m,min);
        }
        cout<<min<<endl;
        a.clear();
        cpy.clear();
    }    

    return 0;
}
