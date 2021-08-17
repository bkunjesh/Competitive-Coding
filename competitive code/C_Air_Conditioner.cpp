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
    int i, j, k, l;

    int m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> a;

    f(i, n) cin >> j >> k >> l, a.push_back({j, {k, l}});
    // sort(a.begin(), a.end());

    int mn = m, mx = m;
    k = 0;
    f(i, n)
    {
        k = a[i].F - k;
        int l = a[i].S.F;
        int r = a[i].S.S;
        if (mx + k < l || mn - k > r)
        {
            // cout << i << " ";
            cout << "NO" << endl;
            return;
        }
        mx = min(mx + k, r);
        mn = max(mn - k, l);
        k = a[i].F;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif