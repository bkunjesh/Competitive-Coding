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
ll level[200005];
vector<ll> g[200005],visited(200005,0);
vector<vector<ll>> lca(200005,vector<ll>(32));
void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    level[node]=0;
    while(!q.empty())
    {
        ll parent=q.front();
        q.pop();
        visited[parent]=1;
        for(auto child:g[parent])
        {
            if(!visited[child])
            {
                lca[child][0]=parent;
                q.push(child);
                level[child]=level[parent]+1;
            }
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
        ll q;cin>>n>>q;
        f(i,n+1) f(j,32) lca[i][j]=-1;
        f(i,n-1) cin>>j>>k,g[j].push_back(k),g[k].push_back(j);

        bfs(1);
        for(j=1;j<32;j++)
        {
            for(i=1;i<=n;i++)
            {
                //cout<<level[i]<<endl;
                if(lca[i][j-1]!=-1)
                {
                    ll x=lca[i][j-1];
                    lca[i][j]=lca[x][j-1];
                }
            }
        }
        // for(j=0;j<32;j++)
        // {
        //     for(i=1;i<=n;i++)
        //     {
        //         cout<<lca[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
        //cout<<level[1]<<" "<<level[2]<<endl;
        while(q--)
        {
            ll a,b;cin>>a>>b;
            ll ans=0;
            k=level[b]-level[a];
            if(k<0) swap(a,b),k=-k;
            ans=level[a]+level[b];
            while(k!=0)
            {
                j=log2(k);
                k-=1<<j;
                b=lca[b][j];
            }
            if(a==b)
            {
               // cout<<a<<endl;
                ans-=(2*level[a]);
            cout<<ans<<endl;
                continue;
            }
            for(i=31;i>=0;i--)
            {
                //cout<<i<<",";
                if(lca[a][i]!=-1&&lca[a][i]!=lca[b][i])
                {
                    a=lca[a][i],b=lca[b][i];
                }
            }
            ans-=(2*level[lca[a][0]]);
            cout<<ans<<endl;
        }
    }
return 0;
}