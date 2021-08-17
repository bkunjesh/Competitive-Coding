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
    cin >> n >> k;
    vector<int> a(n + 1);
    int dp[n + 1][k + 1];
    int prefix[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));
    rep(i, n) cin >> a[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -inf;
            prefix[i][j] = -inf;
        }
    }

    rep(i, n)
    {
        dp[i - 1][0] = 0;
        prefix[i - 1][0] = 0;
        rep(j, k)
        {
            dp[i][j] = max({dp[i - 1][j] + j * a[i], prefix[i - 1][j - 1] + j * a[i]});
            prefix[i][j] = max(prefix[i - 1][j], dp[i][j]);
        }
    }
    int ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][k]);
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
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