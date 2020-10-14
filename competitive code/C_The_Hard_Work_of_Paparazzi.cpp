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

ll n,m;
class node
{
    public:
    ll time;
    ll x;
    ll y;
    ll ind;
    node(ll t,ll x,ll y,ll ind)
    {
        this->time=t;
        this->x=x;
        this->y=y;
        this->ind=ind;
    }
};

vector<node*> g[100005];
vector<ll> visited(100005,0);

ll tym(node* child,node* nd)
{
    return (abs(child->x - nd->x)+abs(child->y - nd->y));
}

ll maxselfie=0;

void dfs(node* nd,ll tm,ll selfie)
{
    visited[nd->ind]=1;
    if(nd->time<tm)
    {
        //cout<<nd->ind<<"------"<<endl;
        return ;
    }
    //cout<<nd->ind<<" ";
    
    if(selfie>maxselfie) maxselfie=selfie;
    tm=nd->time;
    
    for(auto child:g[nd->ind])
    {
        if(!visited[child->ind])
        {
            
            dfs(child,(tm+tym(child,nd)),selfie+1);

            visited[child->ind]=0;
        }
    }
    visited[nd->ind]=0;
}



int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>m>>n;
        // n -> celebrity

        rep(i,n)
        {
            ll tm,x,y;
            cin>>tm>>x>>y;
            node* newnode=new node(tm,x,y,i);

            f(j,n+1) g[j].push_back(newnode);
        }

       node* root=new node(0,1,1,0);
       dfs(root,0,0);

       cout<<maxselfie<<endl;
        


    }
return 0;
}