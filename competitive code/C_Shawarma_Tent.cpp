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
int N = 200005;

int n;

void solve()
{
    int i, j, k, sx, sy, maxpt = 0, ind;
    cin >> n >> sx >> sy;
    vector<pair<int, int>> a;
    f(i, n) cin >> j >> k, a.push_back({j, k});
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    for (i = 0; i < 4; i++)
    {
        int xpos = sx + x[i];
        int ypos = sy + y[i];
        int pt = 0;
        for (auto it : a)
        {
            int d1 = abs(sx - it.F) + abs(sy - it.S);
            int d2 = abs(xpos - it.F) + abs(ypos - it.S) + 1;
            if (d1 == d2)
                pt++;
        }
        if (pt > maxpt)
        {
            maxpt = pt;
            ind = i;
        }
    }
    cout << maxpt << endl;
    cout << sx + x[ind] << " " << sy + y[ind] << endl;
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