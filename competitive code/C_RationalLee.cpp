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
        cin>>n>>k;
        vector<ll> a(n),w(k);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end(),greater<ll>());
        f(i,k) cin>>w[i];
        sort(w.begin(),w.end());
        ll ans=0;
        j=k-1;
        for(i=0;i<k;i++)
        {
            ans+=a[i];
            ll mn=a[i];
            w[i]--;
            if(w[i]!=0)
            {
                j+=w[i];
                mn=a[j];
            }
            ans+=mn;
        }
        cout<<ans<<endl;
    }
return 0;
}