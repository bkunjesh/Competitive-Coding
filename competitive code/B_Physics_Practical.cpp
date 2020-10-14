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
  //  freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    while (t--)
    {
        cin>>n;
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        //f(i,n) cout<<a[i]<<" ";
        ll ans=n+1,ans2=0;
        for(i=n-1;i>=0;i--)
        {
            ll tofind=a[i]/2+a[i]%2;
            auto it=lower_bound(a.begin(),a.end(),tofind);
            ll cnt=(it-a.begin()+(n-1)-i);
            ans=min(ans,cnt);
        }
        cout<<ans;
    }
return 0;
}