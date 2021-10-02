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

vector<int> g[N], visited(N, 0), isspecial(N, 0), childsxor, value, level(N), dval(N, INT_MIN);
int ans = INT_MIN;
int th;

void dfs1(int node, int depth)
{
    // cout << node << endl;
    visited[node] = 1;
    level[node] = depth;
    int mx1 = INT_MIN, mx2 = INT_MIN;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs1(child, depth + 1);
            // if (isspecial[child])
            {
                int d = dval[child] + 1;
                if (d > mx1)
                {
                    mx2 = mx1;
                    mx1 = d;
                }
                else if (d < mx1 && d > mx2)
                {
                    mx2 = d;
                }
            }
            childsxor[node] ^= value[child];
        }
    }
    if (childsxor[node] >= th)
    {
        isspecial[node] = 1;
        dval[node] = max(dval[node], 0ll);
        ans = max({ans, mx1, mx2, mx1 + mx2});
    }
    dval[node] = max({dval[node], mx1, mx2});
    ans = max({ans, mx1 + mx2});
    dbg(node, childsxor[node], mx1, mx2, isspecial[node]);
}
int findDist(int n, vector<int> parent, vector<int> val, int x)
{
    for (int i = 1; i < n; i++)
    {
        // dbg(i, parent[i]);
        g[i].push_back(parent[i]);
        g[parent[i]].push_back(i);
    }
    value = val;
    childsxor = val;
    th = x;
    dfs1(0, 0);
    cout << ans << endl;
    return ans;
}

void solve()
{
    int i, j, k;

    // vector<int> parent = {-1, 0, 0, 1, 1};
    // vector<int> val = {7, 2, 2, 3, 5};
    // int x = 3;
    // findDist(5, parent, val, x);
    vector<int> parent = {-1, 0, 0, 1, 1};
    vector<int> val = {7, 2, 2, 3, 5};
    int x = 3;
    findDist(5, parent, val, x);

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