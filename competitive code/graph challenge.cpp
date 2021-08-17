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

vector<int> g[N], visited(N), dp(N);

void dfs(int node,int parent=-1,int par_trafic)
{
    visited[node] = 1;
    par_trafic += node;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child,node,par_trafic);
        }
    }
    for(auto child:g[node])
    {
        dp[node] = max(dp[node], dp[child]+child);
        dp[child] = max(dp[child], par_trafic);
    }
}

void solve()
{
    int i, j, k;
    
    //{"1:[5]","2:[5]","3:[5]","4:[5]","5:[1,2,3,4]"}
    
    
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
