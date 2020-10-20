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
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0);
    ll dp[n+1][3];
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n)
    {
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][2]+a[i]);
        dp[i][2]=max(dp[i-1][0]+b[i],dp[i-1][1]+b[i]);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
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