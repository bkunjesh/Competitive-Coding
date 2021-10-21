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
	int t;cin>>t;
	while(t--)
	{
		ll n,i,j=0,k,maxlen=0;cin>>n;
		string s,e_seq; cin>>s;
	/*	if(n<=8)                     //JUGAAD*******
		{
		    for(i=0;i<n;i++)
		{
		    for(j=i+1;j<n;j++)
		    {
		        if(s[i]==s[j])
		        {
		            if((s.length()-j+i)>maxlen)
		            maxlen=(s.length()-j+i);
		        }
		    }
		}
		}
		else*/
		{
		int alpha[26]={0};
		f(i,n) alpha[s[i]-'a']++;
		//f(i,26) cout<<alpha[i]<<" ";
		f(i,26)
		if(alpha[i]>1)
	    while(alpha[i]>1)
		{
	        for(k=j;k<n;k++)
	        {
	            if(s[k]=='a'+i)
	            break;
	        }
	        for(j=k+1;j<n;j++)
	        {
	            if(s[j]=='a'+i)
	            break;
	        }
	        //cout<<"i="<<i<<"j="<<j<<"k="<<k<<endl;
	        if(k<n&&j<n)
	        if((n-j+k)>maxlen)
	        {
	                maxlen=(n-j+k);
	                //cout<<"i="<<i<<"j="<<j<<"k="<<k<<endl;
	        }
	        k=j;
	        alpha[i]--;
	    }
		}
		cout<<maxlen<<endl;
	}
	
	return 0;
}
/*
fast
	int t;cin>>t;
	while(t--)
	{
		ll n,i,j,k,maxlen=0; cin>>n;
		string e_seq,s; cin>>s;
		set<string> subsequence;
		for(i=1;i<pow(2,n);i++)
		{
		    string sub="";
		    for (j = 0; j < n; j++) 
            if (i & (1 << j))   //agr binary i ke jth digit(RtoL)1 bit he to include karenge else nahi
            sub += s[j]; 
            
            auto it=find(subsequence.begin(),subsequence.end(),sub);
            if(it!=subsequence.end())
            {
                if(sub.length()>maxlen)
                {
                    maxlen=sub.length();
                     e_seq=sub;
                }
                continue;
            }
            subsequence.insert(sub);
  
		}
		cout<<maxlen<<" "<<e_seq<<endl;
		*/
