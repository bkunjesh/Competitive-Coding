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
const int N=200005;

int n;
vector<pair<int,int>> g[205];
vector<int> visited(205, 0);

void solve()
{
    int i, j, k,p;

    int m, q;
    cin >> n >> m >> p >> q;
    vector<vector<int>> dist(205, vector<int>(205, inf));

    for (i = 0; i < m;i++)
    {
        int x, y, r;
        cin>>x>>y>>r;
        dist[x][y] = r;
        dist[x][x] = 0;
        dist[y][y] = 0;
        // g[x].push_back({y, r});
        // g[y].push_back({x, r});
    }

    for (k = 1; k <= n; k++)
    {
        for (j = 1; j <= n; j++)
        {
            for (i = 1; i <= n; i++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int possibletour=0, cost = 0;

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(dist[x][y]!=inf)
        {
            possibletour++;
            cost += dist[x][y];
        }
        // int ans = (dist[x][y] == inf) ? 0 : dist[x][y];
        // cout << ans << endl;
    }
    cout << possibletour << " " << cost << endl;
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