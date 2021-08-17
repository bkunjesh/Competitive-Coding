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
vector<int> visited(N),mntime(N,1e9+9);
vector<pair<int, int>> g[N];


void dfs(int node,int par)
{
    visited[node] = 1;
    // vector<int> neighbourtimes;
    int res = 0;
    for(auto child:g[node])
    {
        if(!visited[child.F])
        {
            dfs(child.F,node);
            res = max(res, mntime[child.F] + child.S);
            // neighbourtimes.push_back(mntime[child.F] + child.S);
        }
    }
    return res;
    // if(par!=-1&&g[node].size()==1)
    // {
    //     mntime[node] = 0;
    // }
    // else
    // {
    //     sort(neighbourtimes.begin(), neighbourtimes.end(), greater<int>());
    //     mntime[node] = neighbourtimes[0];
    // }
}
void solve()
{
    int i, j, k;
    
    
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