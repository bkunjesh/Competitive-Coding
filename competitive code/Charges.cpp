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

    cin >> n >> k;
    string s;
    cin >> s;
    int dist = 0;
    rep(i, n - 1)
    {
        if (s[i] != s[i - 1])
            dist += 1;
        else
            dist += 2;
    }
    while (k--)
    {
        cin >> j;
        j--;

        int curadjdist = 0;
        if (j - 1 >= 0)
        {
            if (s[j] != s[j - 1])
                curadjdist += 1;
            else
                curadjdist += 2;
        }
        if (j + 1 < n)
        {
            if (s[j] != s[j + 1])
                curadjdist += 1;
            else
                curadjdist += 2;
        }
        s[j] = (s[j] == '0') ? '1' : '0';

        int now = 0;
        if (j - 1 >= 0)
        {
            if (s[j] != s[j - 1])
                now += 1;
            else
                now += 2;
        }
        if (j + 1 < n)
        {
            if (s[j] != s[j + 1])
                now += 1;
            else
                now += 2;
        }
        dist += (now - curadjdist);
        cout << dist << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif