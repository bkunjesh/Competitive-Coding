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
        cin>>n;
        vector<ll> a(n),b(n),d;
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        f(i,n) d.push_back(a[i]-b[i]);
        sort(d.begin(),d.end());
        ll ans=0;
        for(i=0;i<n;i++)
        {
            //cout<<d[i]<<" ";
            auto it=upper_bound(d.begin()+i+1,d.end(),(-d[i]));
            ans+=(d.end()-it);
        }
        cout<<ans<<endl;
    }
return 0;
}