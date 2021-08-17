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
    int i, j, k,sum=0;

    cin >> n;
    vector<int> a(n + 3, 0), pref(n + 1, 0);
    rep(i, n) cin >> a[i], sum += a[i];
    // cout << sum << endl;
    int max_so_far = -inf, mx = -inf;
    rep(i, n)
    {
        max_so_far = max(max_so_far + a[i], a[i]);
        mx = max(mx, max_so_far);
        // cout << mx << " ";
        if (mx > sum)
        {
            cout << "NO" << endl;
            return;
        }
        if (mx == sum && i != n)
        {
            cout << "NO" << endl;
            return;
        }
    }
    // cout << mx << " ";
    if (mx == sum)
    {
        int val = 0;
        for (i = n; i >= 1; i--)
        {
            val += a[i];
            if (val == sum)
                break;
        }
        if (i <= 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

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