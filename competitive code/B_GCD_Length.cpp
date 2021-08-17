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

    int a, b, c;
    cin >> a >> b >> c;
    int mn = min(a, b);
    int mx = max(a, b);

    int mxdig = 5;
    // cout << ((mxdig / pow(10, mx - 1)) == 0) << " ";
    while (floor(mxdig / pow(10, mx - 1)) == 0)
        mxdig *= 5;

    int gcddig = 5;
    while (floor(gcddig / pow(10, c - 1)) == 0)
        gcddig *= 5;

    int mndig = gcddig;
    while (floor(mndig / pow(10, mn - 1)) == 0)
        mndig *= 3;

    if (a > b)
    {
        cout << mxdig << " " << mndig << endl;
    }
    else
    {
        cout << mndig << " " << mxdig << endl;
    }
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