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
const int inf = 1e10;
int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    string s;
    cin >> s;
    int ans = inf - n / 3;
    if (n < 3)
    {
        if (s == "1")
        {
            cout << ans * 2 << endl;
            return;
        }
        if (s == "00")
        {
            cout << 0 << endl;
            return;
        }
        if (s == "01")
        {
            cout << ans - 1 << endl;
            return;
        }
        cout << ans << endl;
        return;
    }

    if (s[0] == '0')
    {
        for (i = 1; i < n; i = i + 3)
        {
            if (s[i] != '1' || (i + 1 < n && s[i + 1] != '1') || (i + 2 < n && s[i + 2] != '0'))
            {
                cout << 0 << endl;
                return;
            }
        }
        if(n%3==2)
            cout << ans - 1 << endl;
        else
        cout << ans << endl;
        return;
    }
    if (s[0] == '1' && s[1] == '0')
    {
        for (i = 2; i < n; i = i + 3)
        {
            if (s[i] != '1' || (i + 1 < n && s[i + 1] != '1') || (i + 2 < n && s[i + 2] != '0'))
            {
                cout << 0 << endl;
                return;
            }
        }
        cout << ans << endl;
        return;
    }
    else
    {
        for (i = 0; i < n; i = i + 3)
        {
            if (s[i] != '1' || (i + 1 < n && s[i + 1] != '1') || (i + 2 < n && s[i + 2] != '0'))
            {
                cout << 0 << endl;
                return;
            }
        }
        if (n % 3 == 0)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
        return;
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