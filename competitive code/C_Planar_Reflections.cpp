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
int dp[1005][1005][2];
int add(int x, int y)
{
    return ((x % mod + y % mod) % mod);
}
int getans(int pos, int rem, int dir)
{
    if (pos < 1 || pos > n)
        return 0;
    if (rem == 1)
        return 0;
    int &res = dp[pos][rem][dir];

    if (res != -1)
        return res;
    res = 0;

    if (dir == 0)
    {
        res = add(res, getans(pos + 1, rem, dir));
        res = add(res, getans(pos - 1, rem - 1, !dir) + 1);
    }
    else
    {
        res = add(res, getans(pos - 1, rem, dir));
        res = add(res, getans(pos + 1, rem - 1, !dir) + 1);
    }
    return res % mod;
}
void solve()
{
    int i, j, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << add(1, getans(1, k, 0)) << endl;
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
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