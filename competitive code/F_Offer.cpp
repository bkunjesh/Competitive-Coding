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

    cin >> n >> k;
    int a[n + 1];
    unordered_map<int, int> m;
    f(i, n) cin >> a[i];
    int ans = 0, val = 0;
    int l = 0, r = 0;
    for (r = 0; r < n; r++)
    {
        if (m[a[r]] == 0)
            val += a[r];
        m[a[r]]++;
        while (val > k)
        {
            m[a[l]]--;
            if (m[a[l]] == 0)
                val -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
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