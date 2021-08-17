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

    int x, y;
    string s;
    cin >> x >> y >> s;
    n = s.size();
    vector<vector<int>> a(n + 2, vector<int>(2, inf));

    if (s[0] == '?')
        a[0][0] = 0, a[0][1] = 0;
    else if (s[0] == 'C')
        a[0][0] = 0;
    else if (s[0] == 'J')
        a[0][1] = 0;

    for (i = 1; i < n; i++)
    {
        if (s[i] == '?')
        {
            a[i][0] = min(a[i - 1][0], a[i - 1][1] + y);
            a[i][1] = min(a[i - 1][1], a[i - 1][0] + x);
                }
        else if (s[i] == 'C')
        {
            a[i][1] = inf;
            a[i][0] = min(a[i - 1][0], a[i - 1][1] + y);
            // if (s[i - 1] == 'J')
            //     a[i][0] = a[i - 1][1] + y;
        }
        else if (s[i] == 'J')
        {
            a[i][0] = inf;
            a[i][1] = min(a[i - 1][1], a[i - 1][0] + x);
            // if (s[i - 1] == 'C')
            //     a[i][1] = a[i - 1][0] + x;
        }
    }
    cout << min(a[n - 1][0], a[n - 1][1]) << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    rep(test, t)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif