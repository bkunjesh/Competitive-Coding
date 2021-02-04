//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e9;
const int N = 105;

int n;
int m;
int k;

vector<int> a(N), b(N), c(18), d(18), visited(2000005);
int allmask, ans = -inf;
void check(int mask)
{
    map<int, int> mp;
    int i;
    for (i = 0; i < k; i++)
    {
        if (mask & (1 << i))
        {
            mp[d[i]] = 1;
        }
        else
        {
            mp[c[i]] = 1;
        }
    }
    int val = 0;
    for (i = 0; i < m; i++)
    {
        if (mp[a[i]] && mp[b[i]])
            val++;
    }
    ans = max(val, ans);
}
void bitmaskig(int mask)
{
    visited[mask] = 1;

    check(mask);

    if (allmask == mask)
    {
        return;
    }

    for (int i = 0; i < k; i++)
        if (!visited[(mask) | (1 << i)])
            bitmaskig((mask) | (1 << i));
}

void solve()
{
    int i, j;

    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    allmask = (1 << k) - 1;

    for (i = 0; i < k; i++)
        cin >> c[i] >> d[i];
    bitmaskig(0);
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