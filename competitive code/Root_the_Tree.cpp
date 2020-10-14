#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;
vector<ll> g[100005];
vector<ll> in(100005);
vector<ll> out(100005);
ll visited[100005],sz;
void dfs(ll node)
{
    visited[node]=1;
    sz++;
    for(auto child:g[node])
    {
        out[node]++;
        in[child]++;
        if(!visited[child])
        {
            dfs(child);

        }
    }
}
int main()
{
    fast
    ll t = 1, i, j,k;
    cin >> t;
    while (t--)
    {
        cin>>n;
        memset(visited,0,sizeof(visited));
        //ans=vector<ll>(n+3,0);
        in=vector<ll>(n+3,0);
        out=vector<ll>(n+3,0);
        for(i=0;i<=n+1;i++) g[i].clear();
        f(i,n-1) cin>>j>>k, g[j].push_back(k);
        ll cnt=0,mx=0;
        rep(i,n)
        {
             if(!visited[i])
             {
                 sz=0;
                 cnt++;
                 dfs(i);
                 mx=max(mx,sz);
             }
            //sz=g[i].size()+1;
            //mx=max(mx,sz);
        }
        //cout<<n-mx<<endl;
        // rep(i,n) cout<<in[i]<<" ";
        // cout<<endl;
        // rep(i,n) cout<<out[i]<<" ";
        // cout<<endl;
        // ll mx=0;
         cnt=0;
         rep(i,n)
         {
             cnt+=in[i]>1?in[i]-1:0;
             //cnt+=out[i]>1?out[i]-1:0;
         }
         cout<<cnt<<endl;

    }
return 0;
}