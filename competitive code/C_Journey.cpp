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
vector<int> g[N], visited(N), sz(N);
double dfs(int node)
{
    visited[node] = 1;
    double ans = 0;
    int flag = 1;
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            flag = 0;
            ans += (dfs(child)+1);
        }
    }
    // cout << node << " " << ans << endl;
    if (flag)
    {
        return 0;
    }
    if(node==1)
        return ans / g[node].size();
    return ans / (g[node].size()-1);
}
void solve()
{
    int i, j, k;

    cin >> n;
    f(i, n - 1) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    cout << fixed << setprecision(15);
    cout << dfs(1) << endl;

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