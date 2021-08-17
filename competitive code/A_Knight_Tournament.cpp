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

    int l[m], r[m], x[m];
    f(i, m) cin >> l[i] >> r[i] >> x[i];
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    set<int> s;
    rep(i, n) s.insert(i);
    f(i, m)
    {
        auto it = s.lower_bound(l[i]);
        vector<int> del;
        while (it != s.end())
        {
            int p = *it;
            if (p > r[i])
                break;
            auto q = it;
            it++;
            if (p != x[i])
            {
                ans[p] = x[i];
                s.erase(q);
            }
        }
    }
    rep(i, n) cout << ans[i] << " ";
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