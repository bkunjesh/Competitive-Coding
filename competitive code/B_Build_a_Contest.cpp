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
    ll t = 1, i, j;
    //cin >> t;
    while (t--)
    {
        ll m;
        cin>>n>>m;
        vector<ll> a(m);
        map<ll,ll> mp;
        f(i,m) cin>>a[i];
        set<ll> s;
        ll o_cnt=0;
        for(i=0;i<m;i++)
        {
            mp[a[i]]++;
            s.insert(a[i]);
            if(s.size()==n)
            {
                cout<<1;
                for(j=1;j<=n;j++)
                {
                    mp[j]--;
                    if(mp[j]==0) s.erase(j);
                }
            }
            else
            {
                cout<<0;
            }
            
        }
    }
return 0;
}