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
vector<ll> g[200005],visited(200005,0),depth(200005,0),maxdist(200005,0);
void cal_depth(ll node,ll parent)
{
    for(auto child:g[node])
    {
        if(child!=parent)
        {
            cal_depth(child,node);
            depth[node]=max(depth[node],1+depth[child]);
        }
    }
}
void max_distance(ll node,ll parent,ll par_max)
{
    vector<ll> prefix,sufix;
    for(auto child:g[node])
    {
        if(child!=parent)
        {
            prefix.push_back(depth[child]);
            sufix.push_back(depth[child]);
        }
    }
    
    for(ll i=1;i<prefix.size();i++)
    {
        prefix[i]=max(prefix[i],prefix[i-1]);
        sufix[sufix.size()-1-i]=max(sufix[sufix.size()-1-i],sufix[sufix.size()-i]);
    }
    sufix.push_back(INT_MIN);
    ll child_no=0;
    for(auto child:g[node])
    {
        if(child!=parent)
        {
            ll partial_max=-1;
            if(child_no>0) partial_max=max(prefix[child_no-1],partial_max);
            partial_max=max(partial_max,par_max);
            partial_max=1+max(sufix[child_no+1],partial_max);
            max_distance(child,node,partial_max);
            child_no++;
        }
    }
    //if(sufix.empty()) sufix.push_back(-1);
    maxdist[node]=max(maxdist[node],sufix[0]+1);
    maxdist[node]=max(maxdist[node],par_max+1);


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
        cal_depth(1,-1);
        max_distance(1,0,-1);
        rep(i,n) cout<<maxdist[i]<<" ";

    }
return 0;
}