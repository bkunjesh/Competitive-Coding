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
    int i, j, k, y;

    cin >> y >> k >> n;

    int xmax = n - y;
    int x = k - y % k;
    vector<int> ans;
    while (x <= xmax)
    {
        ans.push_back(x);
        x += k;
    }
    if (ans.size() == 0)
    {
        cout << -1 << endl;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }

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