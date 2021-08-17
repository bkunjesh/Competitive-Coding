//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // vector<vector<int>> dp(n + 2, vector<int>(3, 0));

    // for (i = 1; i <= n;i++)
    // {
    //     dp[i - 1][0] = max({
    //         dp[i-1][0]+a[i],
    //         a[i]
    //     });

    //     dp[i - 1][1] = max({
    //         dp[i - 1][1] + a[i],
    //         dp[i - 1][1] - a[i],
    //         dp[i - 1][0] - a[i],
    //     });

    //     dp[i - 1][2] = max({
    //         dp[i-1][2]-a[i],
    //         dp[i-1][1]-a[i],

    //     });
    // }

    int dp[n + 3][3][2];

    memset(dp, 0, sizeof(dp));
    int ans = 0;

    for (i = 1; i <= n; i++)
    {
        dp[i][0][0] = max({
            dp[i-1][0][0],
            dp[i - 1][0][0] + a[i],
            a[i]
        });
        // dp[i][0][1]=max({
        // });

        dp[i][1][0] = max({
            dp[i - 1][1][1] + a[i],
            dp[i - 1][1][0],
            dp[i - 1][1][1],

        });

        dp[i][1][1] = max({
            dp[i - 1][0][0] - a[i],
            dp[i - 1][1][1] - a[i],
            -a[i],
        });

        dp[i][2][0] = max({
            dp[i - 1][2][1] - a[i],
            dp[i - 1][2][0],
            dp[i - 1][2][0] + a[i],
        });

        dp[i][2][1] = max({
            dp[i - 1][1][0] - a[i],
            dp[i - 1][2][1] - a[i],
        });

        ans = max({ans, dp[i][0][0], dp[i][1][0], dp[i][1][1], dp[i][2][0], dp[i][2][1]});
    }

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif