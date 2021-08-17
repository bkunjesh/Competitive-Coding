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
    int i, j, q, k;
    cin >> n >> q;
    vector<int> a(n + 1), bits(32, 0);
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        f(j, 32)
        {
            if ((a[i] & (1 << j)))
                bits[j]++;
        }
    }
    int ans = 0;
    f(j, 32)
    {
        if (bits[j] > 0)
        {
            ans += (1 << j);
        }
    }
    cout << ans << endl;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        int cur = a[x];
        a[x] = v;
        f(j, 32)
        {
            if ((cur & (1 << j)))
                bits[j]--;
            if ((v & (1 << j)))
                bits[j]++;
        }
        ans = 0;
        f(j, 32)
        {
            if (bits[j] > 0)
            {
                ans += (1 << j);
            }
        }
        cout << ans << endl;
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