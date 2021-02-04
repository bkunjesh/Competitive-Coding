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

int n, m;
bool is_valid(int s, vector<int> a)
{
    // cout << s << " ";
    int grp = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > s)
        {
            grp++;
            sum = a[i];
        }

        if (grp > m)
            return false;
    }
    return true;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i];
    cin >> m;

    int l = *min_element(a.begin() + 1, a.end());
    int r = 1e13;
    int ans = inf;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (is_valid(mid, a))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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

