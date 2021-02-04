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

    cin >> n;
    vector<int> a(n),prefmax(n),sufmax(n);
    f(i, n) cin >> a[i];
    int ans=inf;
    prefmax[0] = -inf;
    prefmax[1] = a[1]-a[0];
    rew(i, 2, n-1) prefmax[i] = max(prefmax[i - 1], a[i] - a[i - 1]);
    sufmax[n - 1] = -inf;
    sufmax[n - 2] = a[n - 1] - a[n - 2];
    for (i = n - 3; i >= 0;i--)
        sufmax[i] = max(sufmax[i + 1], a[i + 1] - a[i]);
    rep(i, n - 2)
    {
        ans = min(ans,max({prefmax[i-1],sufmax[i+1],a[i + 1] - a[i - 1]}));
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