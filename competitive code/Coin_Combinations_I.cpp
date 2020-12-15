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
const int inf = 1e18;
int N = 200005;

int n;

void solve()
{
    int i, j, k, x;

    cin >> n >> x;
    vector<int> a(n), dp(x + 1, 0);
    f(i, n) cin >> a[i];
    for (i = 1; i <= x; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((i - a[j] >= 0 && dp[i - a[j]] != 0))
            {
                dp[i] = dp[i] + dp[i - a[j]];
                dp[i] %= mod;
            }
            else if (i == a[j])
            {
                dp[i]++;
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << endl;

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