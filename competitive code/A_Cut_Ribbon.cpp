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

    vector<int> a(3);
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> dp(n + 1, 0);

    for (i = 0; i <= n; i++)
    {
        int val = dp[i];
        for (j = 0; j < 3; j++)
        {
            if (i - a[j] > 0 && dp[i - a[j]] > 0)
            {
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            }
            else if (i - a[j] == 0)
            {
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;

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