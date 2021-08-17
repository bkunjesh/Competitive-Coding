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
    int i, j, k, m;

    cin >> n >> m;
    int a[n], b[m];
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    sort(a, a + n);
    rep(i, n - 1) a[i] -= a[0];
    int g = 0;
    rep(i, n - 1) g = __gcd(g, a[i]);

    f(i, m)
    {
        cout << (__gcd(b[i] + a[0], g)) << " ";
    }
    cout << endl;
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