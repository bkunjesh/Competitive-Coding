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

    string s, w = "";
    int x;
    cin >> s >> x;

    n = s.size();
    f(i, n) w += "0";
    f(i, n)
    {
        int posi=1;
        if (i - x >= 0)
            posi = posi&&s[i - x] - '0';
        if (i + x < n)
            posi = posi && (s[i + x] - '0');

        if (posi)
            w[i] = '1';
    }

    for (i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if ((i + x < n && w[i + x] != '0') || (i - x >= 0 && w[i - x] != '0'))
            {
                cout << -1 << endl;
                return;
            }
        }
        else
        {
            if ((i + x < n && w[i + x] == '1') || (i - x >= 0 && w[i - x] == '1'))
            {
                continue;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << w << endl;

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