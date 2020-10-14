#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j,k;
    //cin >> t;
    while (t--)
    {
        cin>>n>>k;
        map<ll,ll> m;
        f(i,n) cin>>j,m[j]=1;
        ll ans=0;
        vector<ll> div;
        for(i=1;i*i<=k;i++)
        {
            ll dv=i;
            if(k%dv==0)
            {
                div.push_back(dv);
                div.push_back(k/dv);
            }
        }
        map<pair<ll,ll>,ll> uniq;
        for(auto dv:div)
        {
            for(auto it:m)
            {
                ll no=it.first;
                //cout<<no<<" ";
                if(m[no]>0&&m[dv+no]==1&&uniq[{no,dv+no}]==0) 
                {
                    ans++,uniq[{no,dv+no}]=1;
                }
                if(m[no]>0&&m[no-dv]==1&&uniq[{no,no-dv}]==0) 
                {
                  // cout<<no<<" "<<no-dv<<endl;
                   uniq[{no,no-dv}]=1;
                    ans++;
                }                
            }
        }
        cout<<ans<<endl;


    }
return 0;
}