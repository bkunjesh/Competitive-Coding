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

    int m;
    cin >> n >> m;
    vector<int> a(n);

    int mp[m];
    memset(mp, 0, sizeof(mp));
    f(i, n) cin >> a[i], a[i] %= m, mp[a[i]]++;

    int ans = 0;
    if (mp[0] > 0)
        ans++, mp[0] = 0;
    for (i = 1; i < m; i++)
    {
        // cout << it.F << " ";

        if (mp[i] == 0)
            continue;
        int cur = i, corr = m - i;
        if (cur == corr && mp[cur] > 0)
        {
            mp[cur] = 0;
            ans++;
            continue;
        }
        if (mp[cur] == mp[corr])
        {
            mp[cur] = 0;
            mp[corr] = 0;
            ans++;
        }
        else if (mp[cur] > mp[corr])
        {
            mp[cur] = mp[cur] - mp[corr] - 1;
            mp[corr] = 0;
            ans++;
            ans += mp[cur];
        }
        else
        {
            mp[corr] = mp[corr] - mp[cur] - 1;
            mp[cur] = 0;
            ans++;
            ans += mp[corr];
            mp[corr] = 0;
        }
        // cout << it.F << " " << mp[it.F] << " " << ans << endl;
    }
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