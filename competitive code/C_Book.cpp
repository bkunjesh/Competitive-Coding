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
vector<int> dp(N, 0);



void solve()
{
    int i, j, k;
    
    cin>>n;
    vector<int> g[n + 2];
    for (i = 1;i<=n;i++)
    {
        cin >> k;
        f(j,k) 
        {
            int u;
            cin>>u;
            g[i].push_back(u);
        }
        sort(g[i].begin(), g[i].end());
    }
    int ans = 0;
    rep(i,n)
    {
        int x = g[i].end() - upper_bound(g[i].begin(), g[i].end(), i);
        ans = max(ans, x);
    }
    cout << ans + 1 << endl;

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