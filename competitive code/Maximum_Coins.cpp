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
        cin>>n;
        vector<vector<ll>> a(n,vector<ll>(n));
        f(i,n) 
        {
            f(j,n) cin>>a[i][j];//,cout<<a[i][j]<<" ";
            //cout<<endl;
        }
        ll x=0;
        ll ans=0;
        for(ll y=0;y<n;y++)
        {
            x=0;
            i=x;
            j=y;
            ll cnt=0;
            while(j<n&&i<n)
            {
                cnt+=a[i][j];
                i++,j++;
            }
            ans=max(ans,cnt);
        }

        ll y=0;
        for(x=0;x<n;x++)
        {
            i=x;
            j=y;
            ll cnt=0;
            while(i<n&&j<n)
            {
                cnt+=a[i][j];
                i++,j++;
            }
            ans=max(ans,cnt);
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;
        
    }
return 0;
}