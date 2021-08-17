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
    int i, j, k,ans=0;

    cin >> n;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];

    vector<int> ld(n + 2, 0), lu(n + 2, 0), rd(n + 2, 0), ru(n + 2, 0);
    vector<int> ldmx(n + 2, 0), lumx(n + 2, 0), rdmx(n + 2, 0), rumx(n + 2, 0);

    rew(i,2,n)
    {
        if(a[i-1]<a[i])
            ld[i] = ld[i - 1] + 1;
        else
            lu[i] = lu[i - 1] + 1;
        lumx[i] = max(lumx[i - 1], lu[i - 1]);
        // ldmx[i] = max(ldmx[i - 1], ld[i - 1]);
    }

    for (i = n - 1; i < 0;i--)
    {
        if(a[i]<a[i+1])
            ru[i] = ru[i + 1] + 1;
        else
            rd[i] = rd[i + 1] + 1;
        rumx[i] = max(rumx[i + 1], ru[i + 1]);
        // rdmx[i] = max(rdmx[i + 1], rd[i + 1]);
    }

    for (i = 1; i <= n;i++)
    {
        if(max(lu[i-ld[i]],ru[i-rd[i]])>=max(ld[i],rd[i]))

    }

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