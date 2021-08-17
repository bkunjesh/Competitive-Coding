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
    string s, t;
    cin >> s >> t;
    map<char, vector<int>> mp, left, right;
    for (i = 0; i < n; i++)
        mp[s[i]].push_back(i);
    int ans = 0;

    int mini[m], maxi[m];
    int cur = -1;
    for (i = 0; i < m; i++)
    {
        int x = upper_bound(mp[t[i]].begin(), mp[t[i]].end(), cur) - mp[t[i]].begin();
        mini[i] = mp[t[i]][x];
        cur = mini[i];
    }
    for (auto &node : mp)
    {
        for (auto &child : node.second)
        {
            child = -child;
        }
        sort(node.second.begin(), node.second.end());
    }

    cur = -n - 1;
    for (i = m - 1; i >= 0; i--)
    {
        int x = upper_bound(mp[t[i]].begin(), mp[t[i]].end(), cur) - mp[t[i]].begin();
        maxi[i] = -mp[t[i]][x];
        cur = -maxi[i];
    }
    rep(i, m-1) ans = max(ans, maxi[i] - mini[i - 1]);
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