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
    vector<ll> visited,in,out,Flattree;
    ll n,timer;
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
};


void solve()
{
    ll i, j, k,m,p;
    cin>>n>>m;
    Graph g(n);
    vector<ll>  lang_employee[102],employee_lang[102];
    for(i=1;i<=n;i++)//i->employee no.
    {
        cin>>j;//j-> no of language known
        for(k=1;k<=j;k++)
        {
            cin>>p;
            employee_lang[i].push_back(p);
            lang_employee[p].push_back(i);
        }
    }
    set<ll> language_known;
    for(i=1;i<=n;i++)
    {
        for(auto langknown:employee_lang[i])
        {
            language_known.insert(langknown);
            for(auto employee:lang_employee[langknown])
            {
                g.make_edge(i,employee);
            }
        }
    }

    ll ans=0;

    for(i=1;i<=n;i++)
    {
        if(!g.visited[i])
        {
            g.dfs(i,-1);
            ans++;
        }
    }
   // cout<<ans<<" "<<m<<" ";
    if(language_known.size()==0) ans++;
    //cout<<language_known.size()<<" ";
    cout<<ans-1<<endl;
    

    return;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}