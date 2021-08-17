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

vector<int> z_function(string s)
{
    int n = s.size(), l = 0, r = 0, i;
    vector<int> z(n);
    for (i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = i, r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;

            if (z[k] < r - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
        // cout << z[i] << " ";
    }

    return z;
}
int n;
void solve()
{
    int i, j, k;

    string a, b;
    cin >> a >> b;

    int bsz = b.size(), asz = a.size();
    int ans = asz + bsz;

    for (i = 0; i < bsz; i++)
    {
        for (j = i+1; j <= bsz; j++)
        {
            int m = j - i;
            string substring = b.substr(i, m);
            string final = substring + '#' + a;
            auto fun = z_function(final);

            for (k = 0; k < fun.size(); k++)
                if (fun[k] == m)
                {
                    ans = min(ans, asz + bsz - m - m);
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