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
vector<ll> g[200005],ans(200005,0),totver(200005,1),totaldist(200005,0);
void cal_ver_below(ll node,ll parent)
{
    for(auto child:g[node])
    if(child!=parent)
    {
        cal_ver_below(child,node);
        totver[node]+=totver[child];
        totaldist[node]+=(totaldist[child]+totver[child]);
    }
}
void total_dist(ll node,ll parent)
{
    for(auto child:g[node])
    {
        if(child!=parent)
        {
            totaldist[child]=totaldist[node]+(n-2*totver[child]);
            total_dist(child,node);           
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
        rep(i,n-1) cin>>j>>k, g[j].push_back(k),g[k].push_back(j);
        cal_ver_below(1,0);
        total_dist(1,0);
        rep(i,n) cout<<totaldist[i]<<" ";
        cout<<endl;

    }
return 0;
}