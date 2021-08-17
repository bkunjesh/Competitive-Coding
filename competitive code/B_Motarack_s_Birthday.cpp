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
    vector<int> a(n);
    f(i, n) cin >> a[i];

    int mn = 1e9, mx = 0;
    rep(i, n - 1)
    {
        if (a[i] == -1)
        {
            if (a[i - 1] != -1)
            {
                mn = min(a[i - 1], mn);
                mx = max(mx, a[i - 1]);
            }
        }
        else if (a[i - 1] == -1)
        {
            mn = min(a[i], mn);
            mx = max(mx, a[i]);
        }
    }
    k = (mn + mx) / 2;
    int ans = 0;
    if (a[0] == -1)
        a[0] = k;
    rep(i, n - 1)
    {
        if (a[i] == -1)
            a[i] = k;
        ans = max(ans, abs(a[i] - a[i - 1]));
    }
    cout << ans << " " << k << endl;
    // int globalmn = inf;
    // auto check = [&](int x) {
    //     int maxdiff = 0;
    //     for (i = 0; i < n; i++)
    //     {
    //         int cur = a[i], prev = a[i - 1];
    //         if (cur == -1)
    //             cur = x;
    //         if (prev == -1)
    //             prev = x;

    //         maxdiff = max(maxdiff, abs(cur - prev));
    //     }
    //     if (maxdiff < globalmn)
    //     {
    //         globalmn = maxdiff;
    //         return 1;
    //     }
    //     return 0;
    // };
    // int l = 0, h = 1e9, ans;
    // while (l < h)
    // {
    //     int mid = l + (h - l) / 2;
    //     cout << mid << " " << globalmn << endl;
    //     if (check(mid))
    //     {
    //         ans = mid;
    //         h = mid - 1;
    //     }
    //     else
    //     {
    //         l = mid + 1;
    //     }
    // }
    // cout << ans << endl;
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