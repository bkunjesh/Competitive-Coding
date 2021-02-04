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
    int a[n+1];
    rep(i, n) cin >> a[i];

    int prefmod[n + 1];
    prefmod[0] = 0;
    rep(i, n) prefmod[i] = (prefmod[i - 1] + a[i]);
    rep(i, n) prefmod[i] %= 7;

    int in[7], out[7];
    memset(in, -1, sizeof(in));
    memset(out, -1, sizeof(out));

    rep(i,n)
    {
        if(in[prefmod[i]]==-1)  in[prefmod[i]] = i;

        out[prefmod[i]] = i;
    }

    int ans = INT_MIN;
    f(i,7)
    {
        if(in[i]!=-1&&out[i]!=-1)
        {
            ans = max(ans, out[i] - in[i]);
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