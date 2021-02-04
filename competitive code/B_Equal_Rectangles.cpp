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
    vector<int> a(4 * n);
    for (int j = 0; j < 4 * n; ++j)
    {
        cin >> a[j];
    }
    sort(a.begin(), a.end());
    int area = a[0] * a.back();
    bool ok = true;
    for (i = 0; i < n; ++i)
    {
        int lf = i * 2, rg = 4 * n - (i * 2) - 1;
        if (a[lf] != a[lf + 1] || a[rg] != a[rg - 1] || a[lf] * 1ll * a[rg] != area)
        {
            ok = false;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

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