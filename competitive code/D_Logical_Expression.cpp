//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<string> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = 1, dp[0][0] = 1;
    rep(i, n) cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        if (a[i] == "AND")
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][1];
        }
    }
    cout << dp[n][1] << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}