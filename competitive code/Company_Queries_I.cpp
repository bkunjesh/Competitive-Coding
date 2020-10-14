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

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        ll q;
        cin>>n>>q;
        
        vector<vector<ll>> lca(n+1,vector<ll>(32));
        f(i,n+1) f(j,32) lca[i][j]=-1;
        rew(i,2,n) cin>>lca[i][0];
        for(j=1;j<32;j++)
        {
            for(i=1;i<=n;i++)
            {
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
        while(q--)
        {
            ll x;
            cin>>x>>k;
            while(k)
            {
                j=log2(k);
                k-=1<<j;
                x=lca[x][j];
                if(x==-1) break;
            }
            cout<<x<<endl;
        }


    }
return 0;
}