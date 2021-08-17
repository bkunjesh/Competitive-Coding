//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
vector<pair<int,int>> g[N];
vector<int> visited(N, 0);
vector<int> dist(N, 0);

void bfs()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int par=q.front();
        visited[par] = 1;
        q.pop();
        
        for(auto child:g[par])
        {
            if(!visited[child.F])
            {
                dist[child.F] = dist[par] ^ child.S;
                q.push(child.F);
            }
        }
    }
}

void solve()
{
    int i, j, k, w;

    cin>>n;
    f(i,n-1)
    {
        cin >> j >> k >> w;
        g[j].push_back({k, w});
        g[k].push_back({j, w});
    }
    bfs();
    int ans = 0;
    for (i = 0; i <= 60;i++)
    {
        int zcnt = 0, ocnt = 0;
        for (j = 1; j <= n;j++)
        {
            if((dist[j]<<i)&1ll)
                ocnt++;
            else
                zcnt++;
        }
        ans =ans%mod + (((1ll << i)%mod) * ((ocnt%mod) * (zcnt%mod)))%mod;
        ans %= mod;
    }
    cout << ans << endl;
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