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
    vector<int> a(n + 1),pref(n+1,0);
    rep(i, n) cin >> a[i],pref[i]=pref[i-1]+a[i];
    int ans = 0;
    for (i = 1; i <= n;i++)
    {
        for (k = i - 1; k > 0;k--)
        if(a[k]<a[i])
            break;
        for (j = i + 1; j <= n; j++)
            if (a[j] < a[i])
                break;
        ans = max((j - k-1) * a[i], ans);
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