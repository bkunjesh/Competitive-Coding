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
vector<ll> g[10000];
vector<ll> visited(10000,0);
void dfs(ll node)
{
    visited[node]=1;
    for(auto child:g[node])
    {
        if(!visited[child])
        {
            dfs(child);
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
        ll s;cin>>n>>s;
        vector<ll> a(n+1),b(n+1);
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];

        rep(i,n)
        {
            if(a[i]==1)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(a[j]==1)
                    {
                        g[i].push_back(j);
                        i=j-1;
                        break;
                    }
                }
            }
        }
        for(i=n;i>0;i--)
        {
            if(b[i]==1)
            {
                for(j=i-1;j>0;j--)
                {
                    if(b[j]==1)
                    {
                        g[i].push_back(j);
                        i=j+1;
                        break;
                    }
                }
            }
        }
        // for(i=1;i<=n;i++)
        // {
        //     cout<<i<<"->";
        //     for(auto child:g[i]) cout<<child<<",";
        //     cout<<endl;
        // }
        dfs(1);
        if(visited[s]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
return 0;
}