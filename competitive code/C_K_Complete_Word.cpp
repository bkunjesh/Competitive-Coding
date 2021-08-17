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
    int i, j, k, ans = 0;

    cin >> n >> k;
    string s;
    cin >> s;
    j = 0;
    // cout << s.substr(0, 7) << " " << s.substr(7, 7) << " " << s.substr(14, 7) << endl;
    for (i = 0; i < (k + 1) / 2; i++)
    {
        map<char, int> m;
        int mx = 0;
        int tot_ele = 0;
        for (j = i; j < n; j += k)
        {
            m[s[j]]++;
            // cout << s[j] << " ";
            int block = j / k;
            int ind = (block + 1) * k - 1;
            tot_ele++;
            if (i != k / 2)
            {
                m[s[ind - i]]++;
                tot_ele++;
                mx = max({mx, m[s[j]], m[s[ind - i]]});
                // cout << s[ind - i] << " ";
            }
            mx = max({mx, m[s[j]]});
        }
        // cout << endl;

        ans += (tot_ele - mx);
    }
    cout << ans << endl;

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