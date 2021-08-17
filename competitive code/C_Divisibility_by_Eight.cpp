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

int toint(string s)
{
    int ans = 0;
    for (auto it : s)
    {
        ans = ans * 10 + (it - '0');
    }
    return ans;
}

void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    n = s.size();

    int goteven = -1, gotodd = -1;

    for (i = 0; i < n; i++)
    {
        int f = s[i] - '0';
        if (f % 8 == 0)
        {
            cout << "YES" << endl;
            cout << f << endl;
            return;
        }
        for (j = i + 1; j < n; j++)
        {
            int sec = s[j] - '0';
            int tdig = f * 10 + sec;
            if (tdig % 8 == 0)
            {
                cout << "YES" << endl;
                cout << tdig << endl;
                return;
            }
            if (tdig % 8 == 0 && goteven != -1)
            {
                cout << "YES" << endl;
                int ans = goteven * 100 + tdig;
                cout << ans << endl;
                return;
            }
            else if ((tdig + 4) % 8 == 0 && gotodd != -1)
            {
                cout << "YES" << endl;
                int ans = gotodd * 100 + tdig;
                cout << ans << endl;
                return;
            }
        }

        (f % 2) ? (gotodd = f) : (goteven = f);
    }
    cout << "NO" << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif