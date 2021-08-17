
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
    vector<int> c(n), f(n), fpref(n + 1, 0), fsuff(n + 1, 0), cfpref(n + 1, 0), cfsuff(n + 1, 0);

    f(i, n) cin >> c[i];
    f(i, n)
    {
        cin >> f[i];
        if (i == 0)
        {
            fpref[i] = 0;
            cfpref[i] = 0;
        }
        else
        {
            fpref[i] = fpref[i - 1] + f[i - 1];
            cfpref[i] = cfpref[i - 1] + c[i - 1] * f[i - 1];
        }
    }
    for (i = n - 2; i >= 0; i--)
    {
        fsuff[i] = fsuff[i + 1] + f[i + 1];
        cfsuff[i] = cfsuff[i + 1] + c[i + 1] * f[i + 1];
    }

    int ans = INT_MAX;

    for (i = 0; i < n; i++)
    {
        int val = (cfpref[i] - fpref[i] * c[i]) + (cfsuff[i] - fsuff[i] * c[i]);
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