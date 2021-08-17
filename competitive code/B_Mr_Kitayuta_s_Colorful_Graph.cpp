//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
vector<pair<int,int>> g[105];
int visited[105],col;

void dfs(int node,int parent=-1)
{
    visited[node] = 1;
    
    for (auto child : g[node])
    {
        if (!visited[child.F]&&child.S==col)
        {
            dfs(child.F,node);
        }
    }
}

void solve()
{
    int i, j, k,c;
    int m,q;
    cin>>n>>m;
    f(i,m) cin>>j>>k>>c,g[j].push_back({k,c}),g[k].push_back({j,c});

    cin>>q;
    while(q--)
    {
        int u,v,ans=0;
        cin>>u>>v;
        int visitedcol[105];
        memset(visitedcol,0,sizeof(visitedcol));
        
        for(auto ch:g[u])
        {
            col=ch.S;
            if(!visitedcol[col])
            {
                visitedcol[col]=1;
                memset(visited,0,sizeof(visited));
                dfs(u);
                if(visited[v]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    
    
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif