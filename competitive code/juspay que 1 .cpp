// //@ikung
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 1005;

// int n, m, t, c;
// vector<int> g[N], visited(N, 0), ans(N, 1e9);
// void bfs()
// {
//     queue<pair<int, int>> q; //node,time
//     q.push({1, 0});
//     visited[1] = 1;
//     while (!q.empty())
//     {
//         auto par = q.front();
//         q.pop();
//         visited[par.first] = 1;
//         int reachToChild;
//         if ((par.second / t) % 2 == 0)
//         {
//             reachToChild = par.second + c;
//         }
//         else
//         {
//             reachToChild = par.second + (t - par.second % t) + c;
//         }
//         for (auto child : g[par.first])
//         {
//             if (!visited[child])
//             {
//                 q.push({child, reachToChild});

//                 ans[child] = min(ans[child], reachToChild);
//             }
//         }
//     }
//     cout << ans[n] << endl;
// }
// void solve()
// {
//     int i, j, k;
//     cin >> n >> m >> t >> c;
//     for (i = 0; i < m; i++)
//         cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
//     bfs();

//     return;
// }

// signed main()
// {
//     int tc = 1, i, j, k;
//     //cin >> tc;
//     while (tc--)
//     {
//         solve();
//     }
//     return 0;
// }
// //#ifndef ONLINE_JUDGE
// //freopen("input.txt", "r", stdin);
// //freopen("output.txt", "w", stdout);
// //#endif

#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1005], visited(1005, 0), dist(1005, 1e9);
int n, m, t, c;
void solve()
{
    int i, j, k, p, x, y, w;

    cin >> n >> m >> t >> c;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[0] = 0;
    queue<int> q;
    q.push(0);
    vector<int> visited(n + 1, 0);
    visited[0] = 1;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (auto i : g[it])
        {
            if (!visited[i])
            {
                dist[i] = dist[it] + 1;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    if (dist[n - 1] >= 1e9)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        x = dist[n - 1];

        int dn = 0;
        int flg = 0;
        int cnt = 0;
        int dis = 0, ti = 0;
        int ans = 0;
        for (ti = 0; dn < x; ti++)
        {
            if ((flg == 0 && dis >= c) || (dis >= c && dn + 1 == x))
            {
                dn++;
                if (dn == x)
                    ans = ti;
                dis = 0;
            }
            if (cnt == t)
            {
                flg ^= 1;
                cnt = 0;
            }
            if (flg == 0 && dis >= c)
            {
                dn++;
                dis = 0;
                if (dn == x)
                    ans = ti;
            }
            cnt++;
            dis++;
        }
        cout << ans << endl;
    }
}

signed main()
{
    solve();
}