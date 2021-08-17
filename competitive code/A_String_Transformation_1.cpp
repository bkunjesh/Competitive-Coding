//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;
    string a, b;

    cin >> n >> a >> b;
    vector<int> g[26], visited(26, 0);

    f(i, n)
    {
        if (a[i] > b[i])
        {
            cout << -1 << endl;
            return;
        }
        if (a[i] != b[i])
            g[a[i] - 'a'].push_back(b[i] - 'a'), g[b[i] - 'a'].push_back(a[i] - 'a');
    }
    int sz = 0;
    function<void(int)> dfs = [&](int node)
    {
        visited[node] = 1;
        sz++;
        for (auto child : g[node])
        {
            if (!visited[child])
            {
                dfs(child);
            }
        }
    };
    int ans = 0;
    f(i, 26)
    {
        sz = 0;
        if (!visited[i] && g[i].size() > 0)
        {
            dfs(i);
            ans += (sz - 1);
        }
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif