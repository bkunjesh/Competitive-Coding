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

    int x;
    cin >> n >> x;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    vector<vector<int>> dp(n + 10, vector<int>(4, inf));

    for (i = 0; i < n; i++)
    {
        dp[i][0] = max(0ll, a[i]);
        dp[i][1] = max(0ll, a[i]);
        dp[i][2] = max(0ll, a[i] * x);

        if (i == 0)
            continue;

        dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i]);
        dp[i][1] = max({dp[i][1], dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]});
        dp[i][2] = max({dp[i][2], dp[i - 1][0] + x * a[i], dp[i - 1][2] + a[i] * x});
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max({ans, dp[i][1], dp[i][2], dp[i][0]});
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

//reference:  https://codeforces.com/blog/entry/66687?#comment-516548
// didn't understand:- https://codeforces.com/contest/1155/submission/53141642