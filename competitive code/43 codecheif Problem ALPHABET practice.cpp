#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
int main()
{
	fast
	string s,p;
	int i,j,k,n;
	int s_count[26]={0};
	cin>>s>>n;
	for(auto it=s.begin();it!=s.end();it++)
	s_count[*it-'a']++;
	vector<string> a;
	f(i,n)
	{
	    cin>>p;
	    a.push_back(p);
	}
	f(i,n)
	{
	    for(j=0;a[i][j]!='\0';j++)
        if(s_count[a[i][j]-'a']!=1)
	        {
	            cout<<"No"<<endl;
	            break;
	        }
	    
	    if(a[i][j]=='\0')
	    cout<<"Yes"<<endl;
	}

	return 0;
}
