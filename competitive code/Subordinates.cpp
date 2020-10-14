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
vector<ll> g[200005];
vector<ll> subordinates(200005,0);
void dfs(ll node,ll parent)
{
    for(auto child:g[node])
    {
        if(child!=parent)
        {
            dfs(child,node);
            subordinates[node]+=subordinates[child]+1;
        }
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
        for(i=2;i<=n;i++)
        {
            cin>>j;
            g[i].push_back(j);
            g[j].push_back(i);
        }
        dfs(1,-1);
        rep(i,n) cout<<subordinates[i]<<" ";
        cout<<endl;
    }
return 0;
}