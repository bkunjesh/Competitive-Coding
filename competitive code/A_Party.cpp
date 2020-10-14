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
#define rew(i,a,b) for(i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;
vector<ll> g[100005];
vector<ll> visited(100005,0ll);
vector<ll> height(100005,0ll);

void dfs(ll node)
{
    visited[node]=0;
    for(auto child:g[node])
    {
        if(!visited[child])
        {
            dfs(child);
            height[node]=max(height[child]+1,height[node]);
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
        rep(i,n) 
        {
            cin>>j;
            if(j!=-1) g[j].push_back(i);
        }

        rep(i,n)
        {
            //memset(visited,0,sizeof(visited));
            if(!visited[i])
            {
                dfs(i);
            }
        }
        ll ans=0;
        rep(i,n) ans=max(ans,height[i]);
        cout<<ans+1<<endl;

    }
return 0;
}