//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    int mndiff = inf;
    vector<int> diff;

    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            break;
        }
        ans++;
        if(i<n-1)
        {
            mndiff = min(mndiff, a[i + 1] - a[i]);
        }
    }
    if(i<n&&a[i]<=mndiff)
        ans++;
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
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