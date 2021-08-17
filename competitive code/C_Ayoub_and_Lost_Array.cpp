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
int mult(int x, int y)
{
    return ((x % mod) * (y % mod)) % mod;
}
int add(int x, int y, int z)
{
    return (x % mod + y % mod + z % mod) % mod;
}

void solve()
{
    int i, j, k;

    int l, r;
    cin >> n >> l >> r;
    int m[3];
    m[0] = m[1] = m[2] = 0;
    while (l <= r && l % 3 != 0)
        m[l % 3]++, l++;

    while (l < r && r % 3 != 0)
        m[r % 3]++, r--;
    if (l < r)
    {
        int x = (r - l) / 3;
        f(j, 3)
        {
            m[j] += x;
        }
        m[0]++;
    }
    else if (l == r)
    {
        if (l % 3 == 0)
            m[0]++;
    }
    f(j, 3)
    {
        // cout << m[j] << " ";
    }


    int dp[n][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = m[0];
    dp[0][1] = m[1];
    dp[0][2] = m[2];
    rep(i, n - 1)
    {
        dp[i][0] = add(mult(dp[i - 1][0], m[0]), mult(dp[i - 1][1], m[2]), mult(dp[i - 1][2], m[1]));
        dp[i][1] = add(mult(dp[i - 1][1], m[0]), mult(dp[i - 1][2], m[2]), mult(dp[i - 1][0], m[1]));
        dp[i][2] = add(mult(dp[i - 1][2], m[0]), mult(dp[i - 1][0], m[2]), mult(dp[i - 1][1], m[1]));
    }
    cout << dp[n - 1][0] % mod << endl;

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