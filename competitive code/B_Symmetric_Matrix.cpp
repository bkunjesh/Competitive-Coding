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
    cin >> t;
    while (t--)
    {
        ll m;cin>>n>>m;
        ll p,q,r,s;
        ll flag1=0,flag2=0;
        map<pair<ll,ll>,ll> mp;
        for(i=0;i<n;i++)
        {
            cin>>p>>q>>r>>s;
            if(q==r) flag2=1;
            if(mp[{r,q}]>0) flag1=1;
            mp[{q,r}]=1;
            //cout<<p<<q<<r<<s<<endl;
        }
        if(m%2||flag2==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
return 0;
}