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

    int a, b;
    cin >> n >> a >> b >> k;
    vector<int> h(n), extramove;
    f(i, n) cin >> h[i];
    f(i, n)
    {
        int move = 0;
        int rem = h[i] % (a + b);
        if (rem == 0)
            rem = a + b;

        rem -= a;
        if (rem > 0)
        {
            extramove.push_back((rem + a - 1) / a);
        }
        else
            ans++;
    }
    sort(extramove.begin(), extramove.end());
    for (auto it : extramove)
    {
        if (k - it >= 0)
            ans++, k -= it;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif