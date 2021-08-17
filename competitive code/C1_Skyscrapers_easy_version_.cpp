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
void getval(int pos, vector<int> &a, vector<int> &left, vector<int> &right)
{
    int res = 0,mn=a[pos];
    for (int i = pos; i >= 1;i--)
    {
        mn = min(mn, a[i]);
        res += mn;
    }
    left[pos] = res;
    res = 0, mn = a[pos];
    for (int i = pos + 1; i <= n;i++)
    {
        mn = min(mn, a[i]);
        res += mn;
    }
    right[pos] = res;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 2,0);
    rep(i, n) cin >> a[i];
    vector<int> left(n + 2, inf), right(n + 2, inf);

    rep(i, n) getval(i, a, left, right);

    int mxval = 0, ind;
    rep(i, n) if (left[i] + right[i] > mxval) ind = i, mxval = left[i] + right[i];

    vector<int> ans(n + 2);
    ans[ind] = a[ind];
    for (i = ind - 1; i >= 1;i--)
    {
        ans[i] = min(ans[i + 1], a[i]);
    }
    for (i = ind + 1; i <= n;i++)
    {
        ans[i] = min(ans[i - 1], a[i]);
    }
    
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
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