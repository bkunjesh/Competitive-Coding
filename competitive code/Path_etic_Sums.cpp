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
class Graph
{
    private:
    vector<vector<ll>> g;
    vector<ll> visited,in,out,Flattree;
    ll n,timer;
    public:
    vector<ll> nodeweight;
    Graph(ll n)
    {
        this->n=n;
        visited.assign(n+1,0);
        g.resize(n+1);
        in.assign(n+1,0);
        out.assign(n+1,0);
        Flattree.assign(2*n+2,0);
        nodeweight.assign(n+1,0);
        this->timer=1;
        
    }
    void make_edge(ll a,ll b)
    {
        g[a].push_back(b),g[b].push_back(a);
    }
    void dfs(ll node,ll parent)
    {
        visited[node]=1;
        in[node]=timer;
        Flattree[timer++]=node;

        for(auto child:g[node])
        {
            if(!visited[child])
            {
                dfs(child,parent);
            }
        }

        out[node]=timer;
        Flattree[timer++]=node;
    }
    void bfs(ll node)
    {
        queue<ll> q;
        q.push(node);
        nodeweight[node]=1;

        while(!q.empty())
        {
            ll top=q.front();
            q.pop();
            visited[top]=1;
            for(auto child:g[top])
            if(!visited[child])
            {
                q.push(child);
                if(nodeweight[top]==1)
                nodeweight[child]=2;
                else nodeweight[child]=1;
            }
        }
    }
};


int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        cin>>n;
        Graph g(n);
        f(i,n-1) cin>>j>>k,g.make_edge(j,k); 
        g.bfs(1);
        rep(i,n) cout<<g.nodeweight[i]<<" ";
        cout<<endl;
        
    }
return 0;
}