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
        vector<ll> a(n+1),b(n+1),p(n+1,0);
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i],p[b[i]]=i;
        ll ans=0;
        if(p[1])
        {
            for(i=2;p[i]==p[i-1]+1;i++);
            if(p[i-1]==n)
            {
                for(j=i;j<=n&&p[j]<=j-i;j++);
                if(j>n)
                {
                    cout<<n-i+1<<endl;
                    return 0;
                }
            }
        }
        rep(i,n)
        {
            //if(p[i]!=0)
            ans=max(ans,p[i]-i+n+1);
        }
        cout<<ans<<endl;

    }
return 0;
}