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
bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.F.F == b.F.F)
    {
        return a.F.S > b.F.S;
    }
    return a.F.F < b.F.F;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<pair<pair<int, int>, int>> a;
    f(i, n) cin >> j >> k, a.push_back({{j, k}, i});
    sort(a.begin(), a.end(), cmp);
    int mn = a[0].F.F;
    int mx = a[0].F.S;
    for (i = 0; i < n; i++)
    {
        if (a[i].F.F < mn || a[i].F.S > mx)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << a[0].S + 1 << endl;

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