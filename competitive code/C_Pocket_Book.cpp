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
const int N = 105;

int n;

void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m;
    vector<string> a(n);
    f(i, n) cin >> a[i];
    int ans = 1;
    for (j = 0; j < m; j++)
    {
        map<int, int> mp;
        f(i, n) mp[a[i][j]]++;
        ans = ((ans % mod) * (mp.size() % mod)) % mod;
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