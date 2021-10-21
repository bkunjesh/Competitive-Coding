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
ll i,a,b,j,k,q,n,m;
//vect_ll a;
//ll visited[100001]={0};
//vect_ll g[100001];
int main()
{
	fast
	int t;cin>>t;
	while(t--)
	{
		//a.clear();
	    cin>>n>>m>>a>>b;
	    ll mat[n][m]={0};
	    if(n*a==m*b)
	    {
	    	cout<<"YES"<<endl;
	    	//a row , b col
	    	f(i,n)f(j,m)mat[i][j]=0;
	    	ll dx;
	    	for (i = 0,dx = 0 ; i < n; i++ , dx += a)
			{
				for ( j = 0; j < a; j++)
					mat[i][(j + dx) % (m )] = 1; 
			}
			f(i,n)
	    	{
	    		f(j,m)
	    		{
	    			cout<<mat[i][j];
				}
				cout<<endl;
			}	    	
		}
	    else cout<<"NO"<<endl;	    
    }	
	return 0;
}
