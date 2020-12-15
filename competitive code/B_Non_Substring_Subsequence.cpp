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
    int i, j, k, q;

    cin >> n >> q;
    string s;
    cin >> s;
    int pref[2][n + 2], suf[2][n + 2];
    pref[0][0] = 0, pref[1][0] = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pref[0][i + 1] = pref[0][i] + 1;
            pref[1][i + 1] = pref[1][i];
        }
        else
        {
            pref[0][i + 1] = pref[0][i];
            pref[1][i + 1] = pref[1][i] + 1;
        }
        //cout << pref[0][i + 1] << " ";
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        //l--, r--;
        if (s[r-1] == '0')
        {
            if (pref[0][n] - pref[0][r] > 0)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        else
        {
            if (pref[1][n] - pref[1][r] > 0)
            {
                cout << "YES" << endl;
                continue;
            }
        }

        if (s[l-1] == '0')
        {
            if (pref[0][l - 1] > 0)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        else
        {
            if (pref[1][l - 1] > 0)
            {
                cout << "YES" << endl;
                continue;
            }
        }

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