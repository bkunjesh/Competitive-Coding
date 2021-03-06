//@CodesUp
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

void solve()
{
    ll i, j, k;
    
    cin>>n>>k;
    vector<ll> a(n);
    f(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=a[k-1]-a[0];
    for(i=k;i<n;i++) ans=min(ans,a[i]-a[i-k+1]);

    cout<<ans<<endl;
    
    return;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}