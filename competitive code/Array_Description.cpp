//@CodesUp
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
const int inf = 1e9;
int N = 200005;

int n;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    vector<int> a(n + 1);
    f(i, n) cin >> a[i];
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i == 0 && (a[i] == 0 || a[i] == j))
            {
                dp[i][j] = 1;
                continue;
            }
            if(i>0)
            {
                if (a[i] == 0 || a[i] == j)
                {
                    dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j + 1] % mod + dp[i - 1][j - 1] % mod) % mod;
                    dp[i][j] %= mod;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    rep(i, m) ans = (ans + dp[n - 1][i]) % mod;
    cout << ans << endl;

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