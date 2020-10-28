//@CodesUp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1), dp[201];
    rep(i, n) cin >> a[i], dp[i].assign(401, inf);
    sort(a.begin() + 1, a.end());
    int ans = INT_MAX, timer = 0;
    for (i = 1; i <= 400;i++)
    {
        dp[1][i] = abs(a[1] - i);
    }
    for (i = 2; i <= n;i++)
    {
        for (j = i; j <= 400;j++)
        {
            for (k = i - 1; k < j;k++)
            {
                dp[i][j] = min(dp[i][j], abs(a[i] - j) + dp[i - 1][k]);
            }
        }
    }
    for (i = 1; i <= 400;i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}