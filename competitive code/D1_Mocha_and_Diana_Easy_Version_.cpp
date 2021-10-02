//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;

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
};

int n;

void solve()
{
    int i, j, k;
    int m1, m2;
    cin >> n >> m1 >> m2;
    DisjointSet d1(n + 2), d2(n + 2);

    for (i = 0; i < m1;i++)
    {
        int u,v;
        cin >> u >> v;
        d1.union_rank(u, v);
    }
    for (i = 0; i < m2;i++)
    {
        int u,v;
        cin >> u >> v;
        d2.union_rank(u, v);
    }
    vector<pair<int, int>> ans;

    for (i = 1; i <= n;i++)
    {
        for (j = i + 1; j <= n;j++)
        {
            if (d1.find(i) != d1.find(j) && d2.find(i) != d2.find(j))
            {
                ans.push_back({i, j});
                d2.union_rank(i,j);
                d1.union_rank(i,j);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x:ans)
    {
        cout << x.F << " " << x.S << endl;
    }

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
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