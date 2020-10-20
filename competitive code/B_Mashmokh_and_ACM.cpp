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

void solve()
{
    ll i, j, k;

    cin>>n>>k;
    ll mat[k+1][n+1]={0};
    for(j=0;j<=n;j++) mat[1][j]=1;
    for(ll l=1;l<k;l++)
    {
        for(j=1;j<=n;j++)
        {
            for(ll p=1;p*j<=n;p++)
            {
                mat[l+1][p*j]+=mat[l][j];
                mat[l+1][p*j]%=mod;
            }
        }
    }
    ll ans=0;
    rep(i,n) ans=(ans+mat[k][i])%mod;
    cout<<ans<<endl;


    return;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}