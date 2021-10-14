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
#define dbg(...) logger(#__VA_ARGS__,__VA_ARGS__)
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


void solve()
{

    int i, j, k;

    cin>>n>>k;
    set<int> g[n+1];
    vector<int> dp(n+1,0);
    f(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue<int> q;

    rep(i,n)
    {
        if(g[i].size()==1)
        {
            q.push(i);
            dp[i]=1;
        }
    }

    while((!q.empty()))
    {
        int sz=q.size();
        while(sz--)
        {
            int node=q.front();
            q.pop();
            
            
            for(auto nb:g[node])
            {
                g[nb].erase(node);
                if(g[nb].size()==1)
                {
                    q.push(nb);
                    dp[nb]=dp[node]+1;
                }
            }
        }
    }

    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(dp[i]>k) ans++;
    }
    cout<<ans<<endl;

return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
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