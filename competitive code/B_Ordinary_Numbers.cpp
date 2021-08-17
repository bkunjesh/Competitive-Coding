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
int getdig(int p)
{
    int ans = 0;
    while (p)
    {
        ans++;
        p /= 10;
    }
    return ans;
}
void solve()
{
    int i, j, k;

    string s;
    cin >> n;
    s = to_string(n);
    int f = s[0] - '0';
    int x = getdig(n);
    int ans = (x - 1) * 9 + f - 1;

    int p = 0;
    f(i, x) p = p * 10 + f;
    if (n >= p)
        ans++;
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