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
    vector<int> price(n), pages(n);
    f(i, n) cin >> price[i];
    f(i, n) cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= x; j++)
        {
            if (i == 0 && j >= price[i])
                dp[i][j] = pages[i];
            if (i > 0 && j >= price[i])
                dp[i][j] = max(dp[i - 1][j], pages[i] + dp[i - 1][j - price[i]]);
            else if (i > 0 && j < price[i])
                dp[i][j] = dp[i - 1][j];
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