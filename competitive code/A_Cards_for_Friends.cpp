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

    int w, h;
    cin >> w >> h >> n;
    int ans = 1;
    int cnt = 0;
    while (w % 2 == 0)
    {
        w /= 2;
        cnt++;
    }
    ans *= pow(2, cnt);
    cnt = 0;
    while (h % 2 == 0)
    {
        h /= 2;
        cnt++;
    }
    ans *= pow(2, cnt);

    if (ans >= n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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