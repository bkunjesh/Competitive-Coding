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
    int a[n];
    f(i, n) cin >> a[i];
    int prefxor[n], prefodd[n], prefeve[n];
    prefxor[0] = a[0];
    prefodd[0] = (a[0] % 2);
    prefeve[0] = !(a[0] % 2);
    int ans = prefeve[0];
    rep(i, n - 1)
    {
        prefxor[i] = prefxor[i - 1] ^ a[i];
        prefeve[i] = prefeve[i - 1] + (!(prefxor[i] % 2));
        prefodd[i] = prefodd[i - 1] + (prefxor[i] % 2);

        ans += (prefxor[i] % 2 == 0) ? prefeve[i] : prefodd[i - 1];

        // cout << i << " " << prefxor[i] << " " << prefodd[i] << " " << prefeve[i] << endl;
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