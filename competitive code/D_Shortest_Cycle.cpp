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
    public:
    vector<vector<ll>> g;
    vector<ll> visited,in,out,Flattree,nodeweight;
    set<ll> nodes;
    ll n,timer;
    
    Graph(ll n)
    {
        this->n=n;
        visited.assign(n+1,0);
        g.resize(n+1);       
    }
    void make_edge(ll a,ll b)
    {
        g[a].push_back(b),g[b].push_back(a);
    }
    ll shortest_cycle(ll n) 
{ 
    // To store length of the shortest cycle 
    ll ans = INT_MAX; 
  
    // For all vertices 
    for (auto node:nodes) { 

        ll i=node;
        // Make distance maximum 
        vector<ll> dist(n, (ll)(1e9)); 
  
        // Take a imaginary parent 
        vector<ll> par(n, -1); 
  
        // Distance of source to source is 0 
        dist[i] = 0; 
        queue<ll> q; 
  
        // Push the source element 
        q.push(i); 
  
        // Continue until queue is not empty 
        while (!q.empty()) { 
  
            // Take the first element 
            ll x = q.front(); 
            q.pop(); 
  
            // Traverse for all it's childs 
            for (ll child : g[x]) { 
  
                // If it is not visited yet 
                if (dist[child] == (ll)(1e9)) { 
  
                    // Increase distance by 1 
                    dist[child] = 1 + dist[x]; 
  
                    // Change parent 
                    par[child] = x; 
  
                    // Push into the queue 
                    q.push(child); 
                } 
  
                // If it is already visited 
                else if (par[x] != child and par[child] != x) 
                    ans = min(ans, dist[x] + dist[child] + 1); 
            } 
        } 
    } 
  
    // If graph contains no cycle 
    if (ans == INT_MAX) 
        return -1; 
  
    // If graph contains cycle 
    else
        return ans; 
} 
    
};

map<ll,vector<ll>> g;

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>n;
        Graph g(100005);
        vector<ll> a(n+1);
        rep(i,n) cin>>a[i];

        for(k=0;k<64;k++)
        {
            vector<ll> b;
            rep(i,n)
            {
                if(a[i]&1)
                {
                    b.push_back(i);
                }
                a[i]>>=1;
            }
            if(b.size()>2)
            {
                cout<<3<<endl;
                return 0;
            }
            if(b.size()==2)
            {
                g.make_edge(b[0],b[1]);
                g.nodes.insert(b[0]);
                g.nodes.insert(b[1]);

            }
        }
        cout<<g.shortest_cycle(n+1)<<endl;

        




    }
return 0;
}