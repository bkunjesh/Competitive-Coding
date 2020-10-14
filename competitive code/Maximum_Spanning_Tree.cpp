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

/*class Node
{
    public:
    ll name;
    //map<ll,ll> link;
    Node(ll n)
    {
        name=n;
    }
};*/
class subset
{
    public:
    ll parent;
    ll rank;
};

class graph
{
    public:
    //vector<Node*> nodes;
    set<pair<ll,pair<ll,ll>>> edges;
    ll n,m;
    graph(ll n,ll m)
    {
        this->n=n;
        this->m=m;
        // for(ll i=0;i<=n;i++)
        // {
        //     Node* temp=new Node(i);
        //     nodes.push_back(temp);
        // }
    }
    void make_edge(ll a,ll b,ll c)
    {
        //nodes[a]->link[b]=c;
        edges.insert({c,{a,b}});
    }
    /*void print_graph()
    {
        for(ll i=0;i<=n;i++)
        {
            cout<<i<<"th node->"<<endl;
            for(auto it:nodes[i]->link)
            {
                cout<<it.F<<","<<it.S<<endl;
            }
        }
    }
    void print_all_edges()
    {
        for(auto edge:edges)
        {
            cout<<edge.F<<"-->{"<<edge.S.F<<","<<edge.S.S<<"}"<<endl;
        }
    }*/
    int find(subset subsets[], int i)  
    {   
        if (subsets[i].parent != i)  
            subsets[i].parent = find(subsets, subsets[i].parent)    ;  
    
        return subsets[i].parent;  
    } 
    void Union(subset subsets[],ll x,ll y)
    {
        ll xroot=find(subsets,x);
        ll yroot=find(subsets,y);
        if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
        else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot; 
        else
        {  
            subsets[yroot].parent = xroot;  
            subsets[xroot].rank++;  
        } 
    }
    void maxmst()
    {
        ll e=0,i=0,ans=0;
        subset* subsets=new subset[((n+1)*sizeof(subset))];
        for(int v=0;v<=n;v++)
        {
            subsets[v].parent=v;
            subsets[v].rank=0;
        }
        auto it=edges.rbegin();
        while(e<n-1&&i<m)
        {
            i++;
            ll x=find(subsets,(*it).S.F);
            ll y=find(subsets,(*it).S.S);

            if(x!=y)
            {
                ans+=(*it).F;
                e++;
                Union(subsets,x,y);
            }
            it++;
        }

        cout<<ans<<endl;

    }
};

int main()
{
    fast
    ll t = 1, i, j,n,m,k;
    cin >> t;
    while (t--)
    {
        ll a,b,c;
        cin>>n>>m;
        //cout<<"main";
        graph g(n,m);
        f(i,m) cin>>a>>b>>c,g.make_edge(a,b,c);
        
        //g.make_edge(1,2,2);
        //g.make_edge(2,3,3);
        //g.make_edge(1,3,4);
        //g.print_graph();
        //g.print_all_edges();
        
        g.maxmst();
        
    }
return 0;
}