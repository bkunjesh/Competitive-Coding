// //@ikung
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);
// #define f(i,k) for(int i=0;i<k;i++)
// #define F first
// #define S second
// #define endl "\n"
// #define rep(i,n) for(int i=1;i<=n;i++)
// #define rew(i,a,b) for(int i=a;i<=b;i++)
// #define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template<typename ...Args>
// void logger(string vars, Args&&... values) {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ","));
//     cout << endl;
// }

// #define mod 1000000007
// const int inf = 1e18;
// const int N=200005;

// int n;
// vector<pair<int, int>> g[N],visited(N,0);

// void solve()
// {
    // int i, j, k,src,m,r;

    // cin >> n >> src >> dest >> k >> m >> r;
//     for (i = 0; i < m;i++)
//     {
//         int a,b,c;
//         cin >> a >> b >> c;
//         g[a].push_back(make_pair(b,c));
//         g[b].push_back(make_pair(a,c));
//     }
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     q.push(make_pair(0,src));
//     visited[src]=1;
//     while(!q.empty())
//     {
//         int cur=q.top().second;
//         int dist=q.top().first;
//         q.pop();
//         if(cur==dest)
//         {

//         }
        

//         return;
// }

// signed main()
// {
//     fast
//     int t = 1, i, j, k;
//     //cin >> t;
//     while (t--)
//     {
//         solve();		
//     }
// return 0;
// }
// //#ifndef ONLINE_JUDGE
// //freopen("input.txt", "r", stdin);
// //freopen("output.txt", "w", stdout);
// //#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e3 + 3, maxk = 1e3+3;

int n, m, k;
// ll d[maxn][maxk];
vector<vector<ll>> d(maxn, vector<ll>(maxk, 1e5));
struct E
{
    int u, w;
};
vector<E> g[maxn];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int i, j, src, dest , r;

    cin >> n >> src >> dest >> k >> m >> r;
    // cin >> n >> m >> k;
    // src--, dest--;
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        // v--, u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    // memset(d, 63, sizeof d);
    // d[0][0] = 0;
    set<pair<ll, pair<int, int>>> q({{0, {src, 0}}});
    d[src][0] = 0;
    ll ans = 1e18;
    while (q.size())
    {
        auto [v, used] = q.begin()->second;
        q.erase(q.begin());
        if(v==dest)
        {
            ans = min(ans, d[v][used]);
        }
        auto upd = [&q](int u, int used, ll nw)
        {
            if (used <= k && nw < d[u][used])
            {
                q.erase({d[u][used], {u, used}});
                d[u][used] = nw;
                q.insert({d[u][used], {u, used}});
            }
        };
        for (auto [u, w] : g[v])
        {
            upd(u, used, d[v][used] + w);
            upd(u, used + 1, d[v][used]);
        }
    }
    // for (int i = 0; i < n; i++)
        // cout << *min_element(d[i], d[i + 1]) << ' ';
    cout << ans << endl;
    cout << '\n';
}