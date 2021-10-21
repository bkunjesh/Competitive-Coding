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
char pre,cur;
//ll visited[100001]={0};
//vect_ll g[100001];
ll solve(ll low, ll high)
{
	ll mid=(low+high)/2;
	cout<<mid<<endl;
    cin>>pre;
	if(pre=='E') 
	{
	//	m=0;
		return 0;
	}
	cout<<mid<<endl;
	cin>>cur;
	if(cur!=pre)
	{
		//while(cur!=pre)
		{
			pre=cur;
			cout<<mid<<endl;
			cin>>cur;
		}
	}
	if(pre=='E'||cur=='E') 
	{
	//	m=0;
		return 0;
	}
	if(cur=='G')
	{
		return solve(mid+1,high);
		//if(m) solve(1,mid);
	}
	else
	{
		return solve(low,mid-1);
	//	if(m) solve(mid+1,n);
	}
}
int main()
{
	fast
//	int t;cin>>t;
//	while(t--)
	{
		a.clear();
	    cin>>n;
	    m=1;
	    solve(1,n);
    }	
	return 0;
}
