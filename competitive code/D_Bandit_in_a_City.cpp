//@bkunjesh
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e18;

class Graph
{
public:
    vector<vector<ll>> g;
    ll n, timer, ans = 0;
    vector<ll>  a;
    Graph(ll n)
    {
        this->n = n;
        g.resize(n + 1);
        a.assign(n + 1, 0);
    }
    void make_edge(ll a, ll b)
    {
        g[a].push_back(b);
    }
    vector<ll> dfs(ll node, ll parent)
    {
        vector<ll> ans(3); //{nl, extra, max}
        ans[0] = 0, ans[1] = 0, ans[2] = 0;
        ll mx = 0, extra = 0;

        vector<vector<ll>> vec;
        for (auto child : g[node])
        {
            {
                auto childans = dfs(child, node);
                mx = max(mx, childans[2]);
                ans[0] += childans[0];
                vec.push_back(childans);
            }
        }
        for (auto it : vec)
        {
            extra += it[1] + it[0] * (mx - it[2]);
        }
        if (g[node].empty())
            ans[0]++;
        ans[2] = mx;
        ll pepgo = min(a[node], extra);
        extra -= pepgo;
        ll left = a[node] - pepgo;
        if (left == 0)
            ans[1] = extra;
        else
        {
            ll newmax = ans[2] + (left + ans[0] - 1) / ans[0];
            ans[2] = newmax;
            ans[1] = ans[0] - left % ans[0];
            if (ans[1] == ans[0])
                ans[1] = 0;
        }
        return ans;
    }
};

ll n;

void solve()
{
    ll i, j, k;

    cin >> n;
    Graph g(200005);
    for (i = 2; i <= n; i++)
    {
        cin >> j;
        g.make_edge(j, i);
    }
    rep(i, n) cin >> g.a[i];
    cout << g.dfs(1, 0)[2] << endl;

    return;
}

int main()
{
    fast
        ll t = 1,i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}