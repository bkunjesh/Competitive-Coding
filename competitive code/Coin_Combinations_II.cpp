//@CodesUp
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    int i, j, k, x;

    cin >> n >> x;
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    vector<int> a(n);
    f(i, n) cin >> a[i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= x; j++)
        {
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            int diff = j - a[i];
            if (diff > 0 && dp[i][diff] != 0)
            {
                dp[i][j] += dp[i][diff];
                dp[i][j] %= mod;
            }
            else if (diff == 0)
            {
                dp[i][j]++;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n - 1][x] << endl;

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