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
    vector<int> a(n + 1, 0), b(n + 1, 0), tm(n + 1, 0);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) cin >> tm[i];
    int ans = 0, prev = 0, dep = 0, arr;
    for (i = 1; i <= n; i++)
    {
        int inway = a[i] - b[i - 1] + tm[i];
        arr = dep + inway;
        dep = max(b[i], arr + (b[i] - a[i] + 1) / 2);
    }
    cout << arr << endl;
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