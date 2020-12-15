//@CodesUp
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
int N=200005;

int n;

void solve()
{
    int i, j, k,r,g,b;
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());
    int d = a[2] - a[1];
    a[1] += min(a[0], d);
    a[0] -= min(a[0], d);
    a[1] += a[0] / 2;
    a[2] += a[0] / 2;
    a[0] =a[0] - a[0] / 2 - a[0]/2;

    int ans = 0;
    ans = a[1];
    a[2] -= a[1];
    ans += min(a[0], a[2]);
    cout << ans << endl;

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