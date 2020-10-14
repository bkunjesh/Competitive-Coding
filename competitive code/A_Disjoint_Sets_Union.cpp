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

class Disjoint
{
    private:
    vector<vector<ll>> list;
    vector<ll> P;
    public:

    Disjoint(ll n)
    {
        P = vector<ll>(n+1);
        list= vector<vector<ll>>(n+1);
        for(int i=0;i<=n;i++) 
        {
            P[i]=i;
            list[i].push_back(i);                
        }
    }

    void Union(ll a,ll b)
    {
        a=P[a];
        b=P[b];

        if(list[a].size()>list[b].size()) 
        swap(a,b);

        for(auto it:list[a]) 
        P[it]=b;

        list[b].insert(list[b].end(),list[a].begin(),list[a].end());
    }

    int Get(ll a)
    {
        return P[a];
    }
};
int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        ll m,n;
        cin>>n>>m;
        Disjoint d(n);
        while(m--)
        {
            string s;cin>>s>>i>>j;
            if(s=="union")
            {
                d.Union(i,j);
            }
            else
            {
                ll a=d.Get(i);
                ll b=d.Get(j);
                if(a==b) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            
        }

    }
return 0;
}