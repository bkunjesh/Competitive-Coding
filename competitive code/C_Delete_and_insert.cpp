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
        string s;cin>>s;
        map<ll,ll> m;
        ll mx=0;
        for(auto it:s) m[it-'A'+1]++,mx=max(mx,m[it-'A'+1]);
        ll dp[27][mx+1];
        for(i=1;i<=26;i++)
        {
           // cout<<m[i]<<endl;
            for(j=1;j<=mx;j++)
            {
                if(m[i]!=0)  dp[i][j]=abs(m[i]-j)*i;
                else dp[i][j]=0;
            }
        }
        ll ans=INT_MAX;
        for(j=1;j<=mx;j++)
        {
            ll cnt=0;
            for(i=1;i<=26;i++) cnt+=dp[i][j];
            cout<<endl;
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;


    }
return 0;
}