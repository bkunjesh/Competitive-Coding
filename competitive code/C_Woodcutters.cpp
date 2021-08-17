//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e10;
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> x(n+2,0), h(n+2,0);
    x[0] = -inf;
    rep(i, n) cin >> x[i] >> h[i];
    x[n + 1] = inf;
    vector<vector<int>> dp(n + 2, vector<int>(3, 0));

    for (i = 1; i <= n;i++)
    {
        //0-not cut
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        
        //1 cut to left
        if(x[i]-h[i]>x[i-1])
            dp[i][1] = max({dp[i][1], dp[i - 1][0]+1,dp[i-1][1]+1});
        if(x[i]-h[i]>x[i-1]+h[i-1])
        {
            dp[i][1] = max({dp[i][1], dp[i - 1][2]+1});
        }

        //cut to right
        if(x[i]+h[i]<x[i+1])
            dp[i][2] = max({dp[i][2], dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2]+1});
        
            
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif