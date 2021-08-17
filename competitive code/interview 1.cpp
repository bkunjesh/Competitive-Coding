
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
// const int N = 200005;

class MEX
{
    typedef std::pair<int, int> interval;
    std::set<interval> s[2];
    std::multiset<int> values;
    void insert_pair(interval p)
    {
        auto [x, y] = p;
        if (x > y)
            std::swap(x, y);
        s[0].insert({x, y});
        s[1].insert({y, x});
    }
    void remove_pair(interval p)
    {
        auto [x, y] = p;
        if (x > y)
            std::swap(x, y);
        s[0].erase({x, y});
        s[1].erase({y, x});
    }

    std::optional<interval> is_end(int x, bool left)
    {
        int idx = left;
        auto it = s[idx].lower_bound({x, 0});
        if (it != s[idx].end() && it->first == x)
            return *it;
        else
            return std::nullopt;
    }

public:
    void insert(int x)
    {
        bool ok = values.find(x) == values.end();
        values.insert(x);
        if (!ok)
            return;
        auto p1 = is_end(x - 1, true);
        auto p2 = is_end(x + 1, false);
        if (p1 && p2)
        {
            interval i = {p1->second, p2->second};
            remove_pair(*p1);
            remove_pair(*p2);
            insert_pair(i);
        }
        else if (p1 && !p2)
        {
            interval i = {p1->second, x};
            remove_pair(*p1);
            insert_pair(i);
        }
        else if (!p1 && p2)
        {
            interval i = {x, p2->second};
            remove_pair(*p2);
            insert_pair(i);
        }
        else if (!p1 && !p2)
        {
            interval i = {x, x};
            insert_pair(i);
        }
    }
    void remove(int x)
    {
        values.erase(values.find(x));
        if (values.find(x) != values.end())
            return;
        auto it = s[1].lower_bound({x, 0});
        if (it->first != x && it->second != x)
        {
            interval p1 = {it->second, x - 1};
            interval p2 = {x + 1, it->first};
            remove_pair(*it);
            insert_pair(p1);
            insert_pair(p2);
        }
        else if (it->first != x && it->second == x)
        {
            interval p = {x + 1, it->first};
            remove_pair(*it);
            insert_pair(p);
        }
        else if (it->first == x && it->second == x)
        {
            remove_pair(*it);
        }
        else if (it->first == x && it->second != x)
        {
            interval p = {it->second, x - 1};
            remove_pair(*it);
            insert_pair(p);
        }
    }
    int get(int x)
    {
        if (values.find(x) == values.end())
            return x;
        auto it = s[1].lower_bound({x, 0});
        return it->first + 1;
    }
};

const int N = 1e5 + 5;
vector<int> g[N], visited(N), path;
void dfs(int node)
{
    visited[node] = 1;
    path.push_back(node);
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
    path.push_back(node);
}
vector<int> solve(int n, vector<vector<int>> &b, vector<int> &c)
{
    int m = b.size(), i, j, k;
    cout << m << endl;
    for (i = 0; i < m; i++)
    {
        // cout << b[i][1] << " " << b[i][0] << endl;
        g[b[i][1]].push_back(b[i][0]);
        g[b[i][0]].push_back(b[i][1]);
    }
    dfs(0);

    for (auto pth : path)
        cout << pth << " ";
    cout << endl;
    vector<int> ans(n), start(n, INT_MAX), end(n, INT_MIN);
    vector<pair<int, int>> interval;
    for (i = 0; i < path.size(); i++)
    {
        start[path[i]] = min(start[path[i]], i);
        end[path[i]] = max(end[path[i]], i);
    }
    for (i = 0; i < n; i++)
        interval.push_back({start[i], end[i]});
    sort(interval.begin(), interval.end());

    MEX mex;
    int ml = 0, mr = -1;
    for (i = 0; i < interval.size(); i++)
    {
        int l = interval[i].first;
        int r = interval[i].second;

        while (ml > l)
        {
            ml--;
            mex.insert(c[path[ml]]);
        }

        while (mr < r)
        {
            mr++;
            mex.insert(c[path[mr]]);
        }
        while (ml < l)
        {
            mex.remove(c[path[ml]]);
            ml++;
        }
        while (mr > r)
        {
            mex.remove(c[path[mr]]);
            mr--;
        }
        ans[path[l]] = mex.get(0);
    }
    return ans;
}

signed main()
{
    fast int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n - 1);
        vector<int> col(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            arr[i].push_back(u);
            arr[i].push_back(v);
        }
        for (int i = 0; i < n; i++)
            cin >> col[i];

        auto ans = solve(n, arr, col);
        // dfs(0, -1, 1);

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    return 0;
}
