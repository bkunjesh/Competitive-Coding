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
    int a[n];
    map<int, int> m;
    f(i, n) cin >> a[i], m[a[i] % k]++;
    int ans = 0;

    for (auto it : m)
    {
        // cout << it.F << " " << it.S << endl;
        if(it.S==0)
            continue;

        if ((k % 2 == 0 && it.F == k / 2) || it.F == 0)
        {
            ans += (m[it.F] % 2) ? m[it.F] - 1 : m[it.F];
        }
        else
            ans += min(2 * m[it.F], 2 * m[k - it.F]);
        m[it.F] = 0, m[k - it.F] = 0;
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