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
    string s;
    cin >> s;
    s = '#' + s;
    vector<int> pre(n + 2, 0), premn(n + 2), premx(n + 2), sufmn(n + 2, inf), sufmx(n + 2, -inf);
    rep(i, n)
    {
        int x = (s[i] == '+') ? 1 : -1;
        pre[i] = pre[i - 1] + x;
        premn[i] = min(premn[i - 1], pre[i]);
        premx[i] = max(premx[i - 1], pre[i]);
    }
    for (i = n; i >= 1; i--)
    {
        sufmn[i] = min(sufmn[i + 1], pre[i]);
        sufmx[i] = max(sufmx[i + 1], pre[i]);
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int rsum = pre[r] - pre[l - 1];
        int val1 = r + 1 <= n ? sufmx[r + 1] - rsum : 0;
        int val2 = r + 1 <= n ? sufmn[r + 1] - rsum : 0;
        int mxx = max(premx[l - 1], val1);
        int mnx = min(premn[l - 1], val2);

        cout << mxx - mnx + 1 << endl;
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