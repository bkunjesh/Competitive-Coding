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
    int m;
    cin >> n >> m;
    int co = 0, ce = 0, ko = 0, ke = 0;
    f(i, n) cin >> j, (j % 2) ? co++ : ce++;
    f(i, m) cin >> j, (j % 2) ? ko++ : ke++;
    int ans = 0;
    if (co < ke)
        ans += co;
    else
        ans += ke;
    if (ce < ko)
        ans += ce;
    else
        ans += ko;

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