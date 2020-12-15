//@CodesUp
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
vector<int> g[N],visited(N);
void dfs(int node,int parent=-1)
{
    visited[node] = 1;
    
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child,node);
        }
    }
}

void solve()
{
    int i, j, k,m;

    cin >> n >> m;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    if(m==n-1)
    {
        cout << 0 << endl;
        return;
    }
    int pre = 1;
    dfs(1);
    vector<pair<int, int>> ans;
    for (i = 1; i <= n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans.push_back({pre, i});
        }
    }
    cout << ans.size() << endl;
    for(auto it:ans)
    {
        cout << it.F << " " << it.S << endl;
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