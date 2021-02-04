//@CodesUp
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

    int m;
    cin >> n >> m;
    bool row[n + 1] = {0}, col[n + 1] = {0};
    int r = 0, c = 0;
    while (m--)
    {
        cin >> j >> k;
        if (row[j] == 0)
        {
            row[j] = 1;
            r++;
        }
        if (col[k] == 0)
        {
            col[k] = 1;
            c++;
        }

        cout << n * n - r * n - c * n + r * c << " ";
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