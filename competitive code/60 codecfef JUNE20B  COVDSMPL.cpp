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
ll i,b,j,k,q,n,m,p,x;
vect_ll a;
ll mat[65][65];
ll visited[100001]={0};
//vect_ll g[65];
void query(ll r1,ll c1,ll r2,ll c2)
{
	if(r1==r2&&c1==c2)
	{
		mat[r1][c1]=1;
		return ;
	}
	ll cord[4];
	// first quadrant (r1+r2)/2+1->r2 , (c1+c2)/2+1->c2
	cord[0]=(r1+r2)/2+1 , cord[1]=(c1+c2)/2+1 , cord[2]=r2 , cord[3]=c2;
	cout<<"1 "<<cord[0]<<" "<<cord[1]<<" "<<cord[2]<<" "<<cord[3]<<endl;
	cin>>x;
	fflush(stdout);
	if(x!=0) query(cord[0],cord[1],cord[2],cord[3]);
	
	// second quadrant r1->(r1+r2)/2 , (c1+c2)/2+1->c2
	cord[2]=(r1+r2)/2 , cord[1]=(c1+c2)/2+1 , cord[0]=r1 , cord[3]=c2;
	cout<<"1 "<<cord[0]<<" "<<cord[1]<<" "<<cord[2]<<" "<<cord[3]<<endl;
	cin>>x;
	fflush(stdout);
	if(x!=0) query(cord[0],cord[1],cord[2],cord[3]);
	
	//third quadrant (r1+r2)/2+1->r2 , c1->(c1+c2)/2
	cord[0]=(r1+r2)/2+1 , cord[3]=(c1+c2)/2 , cord[2]=r2 , cord[1]=c1;
	cout<<"1 "<<cord[0]<<" "<<cord[1]<<" "<<cord[2]<<" "<<cord[3]<<endl;
	cin>>x;
	fflush(stdout);
	if(x!=0) query(cord[0],cord[1],cord[2],cord[3]);
	
	// fourth quadrant r1->(r1+r2)/2, c1->(c1+c2)/2
	cord[2]=(r1+r2)/2 , cord[3]=(c1+c2)/2 , cord[0]=r1 , cord[1]=c1;
	cout<<"1 "<<cord[0]<<" "<<cord[1]<<" "<<cord[2]<<" "<<cord[3]<<endl;
	cin>>x;
	fflush(stdout);
	if(x!=0) query(cord[0],cord[1],cord[2],cord[3]);
}
int main()
{
	fast
	int t;cin>>t;
	while(t--)
	{
		a.clear();
		f(i,65) memset(mat[i],0,sizeof(mat[i]));
	    cin>>n>>p;
	    //r1,c1,r2,c2
	    query(1,1,n,n);
	    cout<<"2"<<endl;
	    rep(i,n)
	    {
	    	rep(j,n) cout<<mat[i][j]<<" ";
	    	cout<<endl;
		}
		cin>>x;
		if(x==-1) return 0;
		fflush(stdout);
    }	
	return 0;
}
