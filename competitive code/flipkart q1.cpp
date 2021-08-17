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
const int N=2000;

int n,m;
vector<int> g[N], incoming(N);


void solve()
{
    int i, j, k;
    cin >> n >> m;
    vector<int> king(n+1),ans(n+1,1);
    for(i=1;i<=n;i++)
        cin >> king[i];
    for(i=0;i<m;i++)
    {
        cin >> j >> k;
        g[j].push_back(k);
        incoming[k]++;
    }
    queue<int> q;
    for(i=0;i<n;i++)
    {   
        if(incoming[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(king[u]!=king[v])
            {
                ans[v] = max(ans[v], ans[u] + 1);
            }
            incoming[v]--;
            if(incoming[v]==0)
            {  
                q.push(v);
            }
        }
    }
    cout << (*max_element(ans.begin(), ans.end())) << endl;

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