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
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        ll boxwt2=n/2;
        ll boxwt1=2*k-n;
        ll ans=0;
        i=n-1;
        if(k>=n) boxwt1=k;
        while(boxwt1--&&i>=0) ans=max(ans,a[i--]);
        ll high=i,low=0;
        while(low<high)
        {
            ans=max(ans,a[high--]+a[low++]);
        }
        cout<<ans<<endl;
    }
return 0;
}