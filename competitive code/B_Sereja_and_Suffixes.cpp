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
    int i, j, k, m;

    cin >> n >> m;
    map<int, int> mp;
    vector<int> a(n), suf(n + 2, 0);
    f(i, n) cin >> a[i];
    for (i = n - 1; i >= 0; i--)
    {
        if (mp[a[i]] == 0)
        {
            mp[a[i]] = 1;
            suf[i] = suf[i + 1] + 1;
        }
        else
        {
            suf[i] = suf[i + 1];
        }
    }
    while (m--)
    {
        cin >> k;
        cout << suf[--k] << endl;
    }

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