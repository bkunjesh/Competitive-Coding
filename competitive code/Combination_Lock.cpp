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
    ll t = 1,test, i, j, k;
    cin >> t;
    rep(test,t)
    {
        ll w;
        cin>>w>>n;
        vector<ll> a(w+1);
        f(i,w) cin>>a[i];
        ll ans=1e18;
        for(i=1;i<=n;i++)
        {
            ll cnt=0;
            //cout<<i<<endl;
            for(j=0;j<w;j++)
            {
                //cout<<abs(i-a[j])<<" "<<n-i+a[j]<<" "<<n-a[j]+i<<endl;
                cnt+=min(abs(i-a[j]),min(n-i+a[j],abs(n-a[j]+i)));
            }
            //cout<<cnt<<endl;
            ans=min(cnt,ans);
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;
        
    }
return 0;
}