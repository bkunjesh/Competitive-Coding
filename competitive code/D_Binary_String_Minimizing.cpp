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
    int ocnt = 0;

    string ans = "", start = "";
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ocnt++;
            ans += '1';
        }
        else
        {
            if (ocnt <= k)
            {
                start += '0';
                k -= ocnt;
            }
            else
            {
                ans += '0';
                j = ans.size()-1;
                //cout << ans << " " << j << " ";
                int p = j - k;
                swap(ans[j], ans[p]);
                break;
            }
        }
    }
    i++;
    while (i < n)
    {
        ans += s[i];
        i++;
    }
    cout << start << ans << endl;

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