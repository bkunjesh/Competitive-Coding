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
const ll inf=1e18;
ll i,b,j,k,q,n,m;
vect_ll a;
//ll visited[100001]={0};
//vect_ll g[100001];
int main()
{
	fast
	int t;cin>>t;
	while(t--)
	{
		a.clear();
		cin>>n;
		input(i,n,a);
		ll odd=0,even=0;
		f(i,n)
		{
			if(i%2!=a[i]%2)
			{
				if(i%2==0) even++;
				else odd++;
			}
		}
		if(odd==even)
		{
			cout<<odd<<endl;
		}	
		else cout<<"-1"<<endl;
    }
	return 0;
}
