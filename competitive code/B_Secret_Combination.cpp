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
    string ans = (s);
    for (i = 0; i < n; i++)
    {
        string temp = s;
        int toAdd = 10 - (s[i] - '0');
        string val = "";
        for (j = i; j < n; j++)
        {
            val += to_string(((s[j] - '0') + toAdd) % 10);
        }
        for (j = 0; j < i; j++)
        {
            val += to_string(((s[j] - '0') + toAdd) % 10);
        }
        ans = min(ans, (val));
    }
    cout << ans << endl;

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