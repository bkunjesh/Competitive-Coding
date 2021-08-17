// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// int n, m, t, c;
// void getans(int r)
// {
//     int ans = 0;
//     if (c == t)
//     {
//         ans = ans + (r - 1) * 2 * c;
//         ans = ans + c;
//         cout << ans << "\n";
//         return;
//     }

//     if (c < t)
//     {
//         int p = ceil((double)t / c);
//         int x = p * c;
//         int ex = max(x, (int)ceil((double(x) / t) * t));
//         while (r >= p)
//         {
//             ans = ans + ex;
//             r = r - p;
//         }
//         ans = ans + r * c;
//         cout << ans << "\n";
//         return;
//     }
//     while (r > 0)
//     {
//         if (r == 1)
//         {
//             ans = ans + c;
//         }
//         else
//         {
//             ans = ans + max(c, (int)ceil((double)c / t) * t);
//         }
//         // cout<<ans<<"\n";
//         r--;
//     }
//     cout << ans << "\n";
// }
// void solve()
// {
    
//     cin >> n >> m >> t >> c;
//     set<int> g[n + 1];
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].insert(v);
//         g[v].insert(u);
//     }
//     vector<int> visited(n + 1, 0);
//     vector<int> par(n + 1, -1);

//     queue<int> q;
//     visited[1] = 1;
//     q.push(1);
//     while (!q.empty())
//     {
//         int flag = 0;
//         int count = q.size();
//         while (count--)
//         {
//             int u = q.front();
//             q.pop();

//             for (auto v : g[u])
//             {
//                 if (!visited[v])
//                 {
//                     visited[v] = 1;
//                     q.push(v);
//                     par[v] = u;
//                 }
//             }
//         }
//     }

//     int x = n;
//     while (par[x] != -1)
//     {
//         int v = x;
//         int u = par[x];
//         g[u].erase(v);
//         x = par[x];
//     }
//     visited = vector<int>(n + 1, 0);
//     int r = 0;

//     queue<int> qu;
//     visited[1] = 1;
//     qu.push(1);
//     while (!qu.empty())
//     {
//         int flag = 0;
//         int count = qu.size();
//         while (count--)
//         {
//             int u = qu.front();
//             qu.pop();
//             if (u == n)
//             {
//                 flag = 1;
//                 break;
//             }

//             for (auto v : g[u])
//             {
//                 if (!visited[v])
//                 {
//                     visited[v] = 1;
//                     qu.push(v);
//                     par[v] = u;
//                 }
//             }
//         }
//         if (flag)
//             break;
//         r++;
//     }
//     if (visited[n] == 0)
//     {
//         cout << -1 << "\n";
//         return;
//     }
//     getans(r);
// }
// signed main()
// {
//     solve();
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

// vector<int> sort_cyclic_shifts(string const& s) {
//   int n = s.size();
//   const int alphabet = 256;

//   vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
//   for (int i = 0; i < n; i++)
//     cnt[s[i]]++;
//   for (int i = 1; i < alphabet; i++)
//     cnt[i] += cnt[i - 1];
//   for (int i = 0; i < n; i++)
//     p[--cnt[s[i]]] = i;
//   c[p[0]] = 0;
//   int classes = 1;
//   for (int i = 1; i < n; i++) {
//     if (s[p[i]] != s[p[i - 1]])
//       classes++;
//     c[p[i]] = classes - 1;
//   }

//   vector<int> pn(n), cn(n);
//   for (int h = 0; (1 << h) < n; ++h) {
//     for (int i = 0; i < n; i++) {
//       pn[i] = p[i] - (1 << h);
//       if (pn[i] < 0)
//         pn[i] += n;
//     }
//     fill(cnt.begin(), cnt.begin() + classes, 0);
//     for (int i = 0; i < n; i++)
//       cnt[c[pn[i]]]++;
//     for (int i = 1; i < classes; i++)
//       cnt[i] += cnt[i - 1];
//     for (int i = n - 1; i >= 0; i--)
//       p[--cnt[c[pn[i]]]] = pn[i];
//     cn[p[0]] = 0;
//     classes = 1;
//     for (int i = 1; i < n; i++) {
//       pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
//       pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
//       if (cur != prev)
//         ++classes;
//       cn[p[i]] = classes - 1;
//     }
//     c.swap(cn);
//   }
//   return p;
// }

// vector<int> suffix_array_construction(string s) {
//   s += "$";
//   vector<int> sorted_shifts = sort_cyclic_shifts(s);
//   sorted_shifts.erase(sorted_shifts.begin());
//   return sorted_shifts;
// }

// vector<int> lcp_construction(string const& s, vector<int> const& p) {

//   // LCP[i]=common prefix in i and i-1 suffix in sorted order.
//   int n = s.size();
//   vector<int> rank(n , 0);
//   for (int i = 0; i < n; i++)
//     rank[p[i]] = i;

//   int h = 0, k;

//   vector<int> lcp(n, 0);
//   for (int i = 0; i < n; i++) {
//     if (rank[i] > 0) {
//       k = p[rank[i] - 1];

//       while (s[i + h] == s[k + h]) h++;

//       lcp[rank[i]] = h;

//       if (h > 0) h--;
//     }

//   }
//   return lcp;
// }

int n, m, t, c, u, v;
set<int> a[1001];
vector<int> g[1001], visited(1001, 0);
multiset<int> total;
void solve(int st, int e, vector<int> total_paths)
{
    total_paths.push_back(st);
    if (st == e)
    {
        total.insert(total_paths.size() - 1);
        return;
    }
    for (auto u : g[st])
    {
        if (visited[u] == 0)
        {
            visited[st] = 1;
            solve(u, e, total_paths);
            visited[st] = 0;
        }
    }
}
void sovle1(int r)
{
    int res = 0;

    if (c < t)
    {
        int p = ceil((double)t / c);
        int x = p * c;
        int ex = max(x, (int)ceil((double(x) / t) * t));
        while (r >= p)
        {
            res = res + ex;
            r = r - p;
        }
        res = res + r * c;
        cout << res << "\n";
        return;
    }

    if (c == t)
    {
        res = res + (r - 1) * 2 * c;
        res = res + c;
        cout << res << "\n";
        return;
    }

    while (r > 0)
    {
        if (r == 1)
        {
            res = res + c;
        }
        else
        {
            res = res + max(c, (int)ceil((double)c / t) * t);
        }
        // cout<<res<<"\n";
        r--;
    }
    cout << res << "\n";
}
void findingres(int r, int c, int t)
{
    int res = 0;

    if (c < t)
    {
        int p = ceil((double)t / c);
        int x = p * c;
        int ex = max(x, (int)ceil((double(x) / t) * t));
        while (r >= p)
        {
            res = res + ex;
            r = r - p;
        }
        res = res + r * c;
        cout << res << "\n";
        return;
    }

    if (c == t)
    {
        res = res + (r - 1) * 2 * c;
        res = res + c;
        cout << res << "\n";
        return;
    }

    while (r > 0)
    {
        if (r == 1)
        {
            res = res + c;
        }
        else
        {
            res = res + max(c, (int)ceil((double)c / t) * t);
        }
        // cout<<res<<"\n";
        r--;
    }
    cout << res << "\n";
}

void secondtypesolution()
{

    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    queue<int> p;
    vis[1] = 1;
    p.push(1);
    while (!p.empty())
    {
        int flag = 0;
        int count = p.size();
        while (count--)
        {
            int u = p.front();
            p.pop();

            for (auto v : a[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    p.push(v);
                    parent[v] = u;
                }
            }
        }
    }

    int x = n;
    while (parent[x] != -1)
    {
        int v = x;
        int u = parent[x];
        a[u].erase(v);
        x = parent[x];
    }
    vis = vector<int>(n + 1, 0);
    int r = 0;

    queue<int> p1;
    vis[1] = 1;
    p1.push(1);
    while (!p1.empty())
    {
        int flag = 0;
        int count = p1.size();
        while (count--)
        {
            int u = p1.front();
            p1.pop();
            if (u == n)
            {
                flag = 1;
                break;
            }

            for (auto v : a[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    p1.push(v);
                    parent[v] = u;
                }
            }
        }
        if (flag)
            break;
        r++;
    }
    if (vis[n] == 0)
    {
        cout << -1 << "\n";
        return;
    }
    findingres(r, c, t);
}
signed main()
{
    cin >> n >> m >> t >> c;

    int edges = m;
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        a[u].insert(v);
        a[v].insert(u);
    }

    if (edges > 10)
    {
        secondtypesolution();
        return 0;
    }
    vector<int> result;
    int w = c;
    solve(1, n, result);
    total.erase(total.begin());
    if (total.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        int val = *total.begin();
        // cout << val << endl;
        sovle1(val);
    }
    return 0;
}