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
    vector<int> a(n), minus(n, 0);
    f(i, n) cin >> a[i];
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        // a[i] = min(a[i], a[i] - minus[i]);
        // ans += max(0ll, a[i] - (n - 1) + i);
        // a[i] = min(a[i], a[i] - (n - 1) + i);
        int extra = max(0ll, a[i] - n);
        int temp = min(minus[i], extra);
        minus[i] -= temp;
        ans += (extra - temp);
        a[i] -= extra;

        for (j = a[i]; j >=2; j--)
        {
            if (minus[i] > 0)
                minus[i]--;
            else
                ans++;

            if (i + j < n)
                minus[i + j]++;
        }
        if (i != n - 1)
            minus[i + 1] += minus[i];
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