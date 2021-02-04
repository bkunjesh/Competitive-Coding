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
vector<int> g[N],visited(N);
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(2 * n);
    
    f(i, 2 * n) cin >> a[i],g[a[i]].push_back(i);
    int ans = g[1][0]+g[1][1];
    visited[g[1][0]] = visited[g[1][1]] = 1;
    int s = g[1][0], d = g[1][1];
    for (i = 2; i <= n;i++)
    {
        if (abs(g[i][0] - s) + abs(g[i][1] - d) < abs(g[i][1] - s) + abs(g[i][0] - d))
        {
            
            ans += abs(g[i][0] - s) + abs(g[i][1] - d);
            s = g[i][0];
            d = g[i][1];
        }
        else{
            
            ans += abs(g[i][1] - s) + abs(g[i][0] - d);
            s = g[i][1];
            d = g[i][0];
        }
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