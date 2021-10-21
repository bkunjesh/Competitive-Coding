#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
int main()
{
    fast
    int n,m,p,i,j;
    cin>>n>>m;
    set<int,greater<int>> s;
    f(i,n+m)
    {
        cin>>p;
        if(p==-1)
        {
            cout<<*s.begin()<<endl;
            s.erase(s.begin());
            //cout<<endl;
            //for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
            continue;
        }
        s.insert(p);
    }
    return 0;
}
