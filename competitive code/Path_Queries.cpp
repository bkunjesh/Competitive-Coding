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

class FenwickTree
{
    //(one based indexing)
    private:
    ll n;
    vector<ll> bit;
    public:
    FenwickTree(ll n)
    {
        this->n=n+1; 
        bit=vector<ll>(n+1,0);
    }
    ll sum(ll ind)
    {
        ll ret=0;
        for(ind++;ind>0;ind=ind-(ind&-ind))
        ret+=bit[ind];

        return ret;        
    }

    ll sum(ll l,ll r)
    {
        return sum(r)-sum(l-1);
    }

    void add(ll ind,ll val)
    {
        for(ind++;ind<n;ind=ind+(ind&-ind))
        bit[ind]+=val;
    }

};






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
        Flattree[timer++]=-node;
    }
    void PrintFlattree()
    {
        for(ll i=1;i<2*(n)+1;i++)
        cout<<Flattree[i]<<" ";
        cout<<endl;
    }
    vector<ll> getflattree()
    {
        return Flattree;
    }
    ll getstart(ll node)
    {
        return in[node];
    }
    ll getend(ll node)
    {
        return out[node];
    }

};






int main()
{
    fast
    ll t = 1, i, j, k,n;
    //cin >> t;
    while (t--)
    {
        ll q;
        cin>>n>>q;
        Graph graph(n);
        rep(i,n) cin>>graph.nodeweight[i];
        f(i,n-1) cin>>j>>k,graph.make_edge(j,k);
        graph.dfs(1,-1);
        //graph.PrintFlattree();
        vector<ll> flattree = graph.getflattree();
        
        FenwickTree fenwick(2*(n)+1);

        for(ll i=1;i<2*(n)+1;i++)
        {

            ll val=graph.nodeweight[abs(flattree[i])];
            if(flattree[i]<0) val=-val;

            fenwick.add(i,val);
        }

        while(q--)
        {
            ll no;cin>>no;
            if(no==2)
            {
                ll s,l,r;cin>>s;
                l=graph.getstart(1);
                r=graph.getstart(s);
                cout<<fenwick.sum(l,r)<<endl;
            }
            else
            {
                ll s,l,r,x;cin>>s>>x;
                l=graph.getstart(s);
                r=graph.getend(s);
                ll valadd1=x-graph.nodeweight[s];
                ll valadd2=-x+graph.nodeweight[s];
                graph.nodeweight[s]=x;
                fenwick.add(l,valadd1);
                fenwick.add(r,valadd2);                
            }
            
        }        
    }
return 0;
}