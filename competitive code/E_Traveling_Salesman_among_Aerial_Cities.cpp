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
int x[18], y[18], z[18];
int dp[1 << 19][18];
int dist(int a,int b)
{
    return abs(x[a] - x[b]) + abs(y[a] - y[b]) + max(0ll,(z[b] - z[a]));
}

int tsp(int mask,int pos)
{
    if(mask==((1<<n)-1))
    {
        return dist(pos, 0);
    }

    int ans = INT_MAX;

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    for (int city = 0; city < n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int curans = dist(pos, city) + tsp(mask | (1 << city), city);
            ans = min(curans, ans);
        }
    }

    return dp[mask][pos]=ans;
}
void solve()
{
    int i, j, k;

    cin >> n;
    memset(dp, -1, sizeof(dp));
    f(i, n) cin >> x[i] >> y[i] >> z[i];
    cout << tsp(1, 0) << endl;

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

