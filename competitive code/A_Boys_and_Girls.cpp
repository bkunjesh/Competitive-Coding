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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, k;
    
    int m;
    cin >> n >> m;
    string s;
    if(n>m)
        s = "BG";
    else
        s = "GB";

    string ans = "";
    for (i = 0; i < min(n, m);i++)
        ans += s;
    if(n>=m)
    {
        n -= m;
        for (i = 0; i < n;i++)
            ans += "B";
    }
    else
    {
        m -= n;
        for (i = 0; i < m; i++)
            ans += "G";
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