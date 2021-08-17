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

    int c;
    cin >> n >> c;
    vector<int> a(n + 1), b(n + 1), extra(n + 1, 0), days(n + 1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];

    int prevdays = 0, prevextra = 0;
    for (i = 1; i <= n; i++)
    {
        days[i] = days[i - 1] + prevdays;
        extra[i] = prevextra;

        int need_b = b[i] - extra[i];
        if (need_b < 0)
        {
            prevdays = 1;
            prevextra = extra[i] - b[i];
        }
        else
        {
            prevdays = (need_b + a[i] - 1) / a[i];
            prevextra = extra[i] + prevdays * a[i] - b[i];
            prevdays++;
        }
    }
    int ans = inf;
    // for (i = 1; i <= n; i++)
    //     cout << days[i] << " ";
    // cout << endl;
    // for (i = 1; i <= n; i++)
    //     cout << extra[i] << " ";
    // cout << endl;

    for (i = 1; i <= n; i++)
    {
        int val = days[i];
        int need_c = c - extra[i];

        if (need_c > 0)
            val += ((need_c + a[i] - 1) / a[i]);
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