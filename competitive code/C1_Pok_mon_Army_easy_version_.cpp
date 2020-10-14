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
    cin >> t;
    while (t--)
    {
        ll q;cin>>n>>q;
        vector<ll> a(n+1);
        rep(i,n) cin>>a[i];
        vector<ll> ps(n+1,-inf),ng(n+1,0);
        for(i=1;i<=n;i++)
        {
            ps[i]=max(ps[i-1],ng[i-1]+a[i]);
            ng[i]=max(ng[i-1],ps[i-1]-a[i]);
        }
        cout<<max(ps[n],ng[n])<<endl;
        
    }
return 0;
}