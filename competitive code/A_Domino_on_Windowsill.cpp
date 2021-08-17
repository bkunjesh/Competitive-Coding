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

    int k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;

    int whitemin = min(k1, k2);
    int blackmin = n - max(k1, k2);
    
    w -= whitemin;
    b -= blackmin;

    // if (whitemin < w || blackmin < b || abs(k2 - k1) % 2 != 0)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    int need = abs(k2 - k1) / 2;
    w -= need;
    b -= need;
    if (w > 0 || b >0)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

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