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

    int C;
    cin >> n >> C;
    vector<int> a(n), b(n), c(n);
    set<int> s;
    f(i, n) cin >> a[i] >> b[i] >> c[i], s.insert(a[i]), s.insert(b[i] + 1);

    int ind = 0;
    unordered_map<int, int> mp;
    for (auto it : s)
        mp[it] = ind++;

    vector<int> diff(s.size());

    for (i = 0; i < n; i++)
    {
        diff[mp[a[i]]] += c[i];
        diff[mp[b[i] + 1]] -= c[i];
    }
    vector<int> v(s.begin(), s.end()), acc(s.size());
    acc[0] = diff[0];
    int ans = 0;
    for (i = 0; i < s.size() - 1; i++)
    {
        if (i > 0)
            acc[i] = acc[i - 1] + diff[i];
        int span = v[i + 1] - v[i];
        ans += min(C, acc[i]) * span;
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