//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;
vector<ll> g[200005],visited(200005,0);
vector<vector<ll>> dp(200005,vector<ll>(2));
ll maxnode,maxlen=0,len=0;
void dfs(ll node,ll parent,ll len)
{
    if(maxlen<len)
    {
        maxlen=len;
        maxnode=node;
    }
    for(auto child:g[node])
    if(child!=parent)
    {
        dfs(child,node,len+1);
    }

}
int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>n;
        f(i,n-1) cin>>j>>k,g[j].push_back(k),g[k].push_back(j);
        dfs(1,-1,0);
        dfs(maxnode,-1,0);
        cout<<maxlen<<endl;

        
    }
return 0;
}