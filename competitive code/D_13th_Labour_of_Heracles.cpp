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

void solve()
{
    int i, j, k;
    cin>>n;
    int w[n+1];
    int deg[n + 1];
    int ans[n+1];
    priority_queue<int> q;
    memset(ans, 0, sizeof(ans));
    memset(deg, 0, sizeof(deg));

    rep(i, n) cin >> w[i],ans[1]+=w[i];

    f(i, n - 1) cin >> j >> k,deg[j]++,deg[k]++;

    rep(i,n)
    {
        deg[i]--;
        while(deg[i]--)
            q.push(w[i]);
    }

    for (i = 2; i < n;i++)
    {
        ans[i] = ans[i - 1] + q.top();
        q.pop();
    }

    rep(i, n - 1) cout << ans[i] << " ";
    cout << endl;

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