//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
const int inf = 1e9 + 9;
const int N = 200005;

int n;

void solve()
{
    int i, j, k, d;
    cin >> n >> d;

    vector<pair<int, int>> a;
    f(i, n) cin >> j >> k, a.push_back({j, k});
    a.push_back({-inf, 0});
    sort(a.begin(), a.end());
    vector<long long> pref(n + 2, 0);

    pref[1] = a[1].S;
    for (i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i].S;

    long long ans = 0;
    for (i = 1; i <= n; i++)
    {
        int left = a[i].F, right = a[i].F + d;
        // int l = upper_bound(a.begin(), a.end(), make_pair(left, inf)) - a.begin();
        int r = lower_bound(a.begin(), a.end(), make_pair(right, -1)) - a.begin();
        // cout << r << " " << l<<" "<<pref[r-1]<<" "<<pref[l-1] << endl;
        ans = max(ans, pref[r - 1] - pref[i-1]);
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