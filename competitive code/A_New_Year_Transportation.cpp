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
vector<ll> g[100000];
vector<ll> visited(100000,0);
void dfs(ll node)
{
    visited[node]=1;
    for(auto it:g[node])
    {
        if(!visited[it])
        {
            dfs(it);
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
        ll des;
        cin>>n>>des;
        for(i=1;i<=n-1;i++)
        {
            cin>>j;
            g[i].push_back(i+j);
        }
        dfs(1);
        if(visited[des]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
    }
return 0;
}