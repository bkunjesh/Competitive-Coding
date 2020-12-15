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
    int i, j, k, m;

    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
    dp[0][0] = 0;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            if (i > 0 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << dp[n][m];

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