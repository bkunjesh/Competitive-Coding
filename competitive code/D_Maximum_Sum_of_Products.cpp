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

    cin >> n;
    vector<int> a(n + 2), b(n + 2), prefsum(n + 2, 1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    prefsum[0] = 0;
    rep(i, n) prefsum[i] = prefsum[i - 1] + a[i] * b[i];
    int ans = prefsum[n];
    rep(i, n)
    {
        j = i, k = i;
        int sum = -a[j] * b[k];
        while (j >= 1 && k <= n)
        {
            sum += (a[j] * b[k] + a[k] * b[j]);
            ans = max(ans, prefsum[j - 1] + sum + (prefsum[n] - prefsum[k]));
            j--, k++;
        }
        j = i, k = i + 1;
        sum = 0;
        while (j >= 1 && k <= n)
        {
            sum += (a[j] * b[k] + a[k] * b[j]);
            ans = max(ans, prefsum[j - 1] + sum + (prefsum[n] - prefsum[k]));
            j--, k++;
        }
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