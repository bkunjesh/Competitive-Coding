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
#define rep(i,n) for(i=1;i<=n;i++)
#define input(i,n,arr) for(i=0;i<n;i++) cin>>j, arr.push_back(j)
#define vect_ll vector<long long> 
#define vect_ll_it vector<long long>::iterator
#define pb(p) push_back(p)
#define endl "\n"
#define mod 1000000007
ll i,a,b,j,k,q,n,m;
//ll visited[100001]={0};
//vect_ll g[100001];
ll sumOfGP(ll a, ll r, ll n) 
{ 
    return (a * (1 - pow(r, n))) / (1 - r); 
} 

int main()
{
	fast
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>a;
		ll power[n+1];
		power[0]=0;
		for(i=1;i<=n;i++)
		{
		    power[i]=power[i-1]+2*i-1;
		}
		//for(i=0;i<=n;i++) cout<<power[i]<<" ";
		
		ll ans=0;
		for(i=1;i<=n;i++)
		{
		    ans+=pow(a,power[i]);
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}
