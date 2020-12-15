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
    int i, j, k;

    cin >> n;
    // 1 2 3 -> {1,2} {3}
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= sum ; j++)
        {

            dp[i][j] += dp[i - 1][j];
            if (j >= i)
                dp[i][j] += dp[i - 1][j - i],dp[i][j]%=mod;
            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][sum] << endl;

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