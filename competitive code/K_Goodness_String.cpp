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

    string s;
    cin >> n >> k >> s;
    s = " " + s;
    int goodness = 0, ans = 0;
    for (i = 1; i <= n / 2; i++)
    {
        if (s[i] != s[n - i + 1])
            goodness++;
        if (goodness > k)
        {
            s[i] = s[n - i + 1];
            goodness--;
            ans++;
        }
    }
    if (goodness < k)
    {
        for (i = 1; i <= n / 2; i++)
        {
            if (s[i] == s[n - i + 1])
            {
                if (s[i] != 'Z')
                    s[i] = s[i] + 1;
                else
                    s[i] = 'A';
                goodness++;
                ans++;
            }
            if (goodness == k)
            {
                break;
            }
        }
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cout << "case #" << i << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif