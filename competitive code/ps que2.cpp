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

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    vector<int> a(n), pref(n + 2, 0);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = inf;
    rep(i, n) pref[i] = pref[i - 1] + a[i - 1];
    auto getsum = [&](int l, int r)
    {
        return pref[r] - pref[l];
    };
    // cout << getsum(0, 5) << endl;
    for (i = 0; i < n; i++)
    {
        auto x = lower_bound(a.begin() + i + 1, a.end(), a[i] + k) - a.begin();
        // cout << x << endl;
        int val = 0, afterlen = n - x;
        val += (getsum(x, n) - afterlen * (a[i] + k));
        val += (i * (a[i]) - getsum(0, i));
        ans = min(ans, val);

        x = lower_bound(a.begin(), a.begin() + i, a[i] - k) - a.begin();
        val = 0;
        val += (x * (a[i] - k) - getsum(0, x));
        afterlen = n - i;
        val += (getsum(i, n) - afterlen * a[i]);
        ans = min(ans, val);
    }

    cout << ans << endl;
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