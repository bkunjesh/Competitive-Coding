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
//const int N=200005;

int n;

struct DisjointSet
{
    int *rank, *parent;
    DisjointSet(int N)
    {
        rank = new int[N + 1];
        parent = new int[N + 1];
        for (int i = 0; i <= N; i++)
        {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_rank(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        if (rank[pa] > rank[pb])
        {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
        else
        {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
    }
    int getans(int n)
    {
        set<int> s;
        rep(i, n)
        {
            // cout << i << " " << parent[i] << " " << endl;
            s.insert(parent[i]);
        }
        return s.size();
    }
};

vector<int> g[26];
void solve()
{
    int i, j, k;

    cin >> n;
    DisjointSet d(n + 1);
    vector<string> a(n + 1);
    rep(i, n) cin >> a[i];
    j = 1;
    rep(i, n)
    {
        for (auto it : a[i])
        {
            g[it - 'a'].push_back(i);
        }
        j++;
    }
    f(i, 26)
    {
        for (j = 1; j < g[i].size() && g[i].size() > 0; j++)
        {

            d.union_rank(g[i][0], g[i][j]);
            // cout << d.getans(n) << endl;
        }
    }
    rep(i, n)
    {
        d.find(i);
    }
    cout << d.getans(n) << endl;

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