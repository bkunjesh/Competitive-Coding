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
void getNewCordinate(int &x, int &y, char ch)
{
    if (ch == 'L')
        x--;
    else if (ch == 'R')
        x++;
    else if (ch == 'U')
        y++;
    else
        y--;
}
void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    n = s.size();
    int block_x = 0, block_y = 0;
    for (i = 0; i < n; i++)
    {
        getNewCordinate(block_x, block_y, s[i]);
        int x = 0, y = 0;
        for (j = 0; j < n; j++)
        {
            int p = x, q = y;
            getNewCordinate(p, q, s[j]);
            if (p == block_x && q == block_y)
                continue;
            x = p, y = q;
        }
        if (x == 0 && y == 0)
        {
            cout << block_x << " " << block_y << endl;
            return;
        }
    }
    cout << 0 << " " << 0 << endl;

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