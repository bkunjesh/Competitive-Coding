//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k;
    cin >> n;
    vector<int> b, c;
    vector<pair<int, int>> a;
    f(i, n) cin >> j, b.push_back(j);
    f(i, n) cin >> j, c.push_back(j);
    f(i, n) a.push_back({b[i], c[i]});
    sort(a.begin(), a.end());
    vector<int> suf(n + 1, 0);
    for (i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + a[i].S;
    }
    suf[n] = INT_MAX;
    int ans = min(suf[0], a[n - 1].F);
    for (i = 0; i < n; i++)
    {
        ans = min(ans, max(a[i].F, suf[i + 1]));
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