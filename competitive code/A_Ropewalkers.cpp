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
        vector<ll> a(3);
        cin>>a[0]>>a[1]>>a[2]>>n;
        sort(a.begin(),a.end());
        ll ans=0;
        //cout<<a[0]<<" "<<a[2]<<endl;
        if(a[1]-a[0]<n)
        {
            ans+=(a[0])-(a[1]-n);
        }
        if(a[2]-a[1]<n)
        {
            ans+=(a[1]+n)-(a[2]);
        }
        cout<<ans<<endl;

    }
return 0;
}