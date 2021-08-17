//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200005;

int n, m, t, c;

vector<int> g[1001], visited(1005, 0);
vector<pair<int, vector<int>>> path;

void dfs(int st, int e, vector<int> result)
{
    result.push_back(st);
    if (st == e)
    {
        path.push_back({c * (result.size() - 1), result});
        return;
    }
    for (auto u : g[st])
    {
        if (visited[u] == 0)
        {
            visited[st] = 1;
            dfs(u, e, result);
            visited[st] = 0;
        }
    }
}

void solve()
{
    int i, j, k, u, v;

    cin >> n >> m >> t >> c;

    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> result;

    dfs(1, n, result);
    sort(path.begin(), path.end());
    vector<int> rt[n + 1];
    for (int i = 0; i < path.size(); i++)
    {
        int nes = path[i].second.size();
        for (auto u : path[i].second)
        {
            rt[u].push_back(nes);
        }
    }
    int trt[n + 1] = {0};
    trt[1] = 1;
    trt[n] = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (rt[i].size() > 0)
        {
            int tm = rt[i][0];
            int up = upper_bound(rt[i].begin(), rt[i].end(), tm) - rt[i].begin();
            trt[i] = up;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << trt[i] << " ";

    return;
}

signed main()
{

    solve();

    return 0;
}