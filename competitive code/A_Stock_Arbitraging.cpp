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
    int m, r;
    cin >> n >> m >> r;
    vector<int> a(n), b(m);
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int mn = a[0];
    int sell = b[0];

    if (sell <= mn)
    {
        cout << r << endl;
        return;
    }
    int stock = r / a[0];
    int bur = r % a[0];
    bur += (stock * sell);

    cout << bur << endl;

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