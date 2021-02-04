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
    int i, j, k, ans = 0;

    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    for (i = 0; i < n; i++)
    {
        int p = upper_bound(a.begin(), a.end(), a[i] + k) - (a.begin());
        p -= i;
        //cout << p << " ";
        p--;

        if (p >= 2)
            ans += (p - 1) * (p) / 2;
    }

    cout << ans << endl;
    return;
}


signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

