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
    string s;
    cin >> s;
    s = '#' + s;
    map<pair<int, int>, int> m;
    m[{0, 0}] = 0;
    int x = 0, y = 0, start = -1, end = n + 1;
    // cout << s << endl;
    rep(i, n)
    {
        if (s[i] == 'R')
            x++;
        else if (s[i] == 'L')
            x--;
        else if (s[i] == 'U')
            y++;
        else if (s[i] == 'D')
            y--;
        // cout << x << " " << y << endl;
        if ((x == 0 && y == 0) || m[{x, y}] != 0)
        {
            if (end - start + 1 > i - m[{x, y}])
            {
                start = m[{x, y}] + 1;
                end = i;
            }
        }
        m[{x, y}] = i;
    }
    if (start == -1)
        cout << -1 << endl;
    else
        cout << start << " " << end << endl;
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