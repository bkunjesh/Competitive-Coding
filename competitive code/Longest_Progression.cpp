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
    vector<int> a(n);
    f(i, n) cin >> a[i];
    i = n - 1;
    j = n - 1;
    int ans = 1;
    while (j > 0)
    {
        i = j;

        int diff = a[i - 1] - a[i];
        int val = 0;
        while (i - 1 >= 0 && a[i - 1] - a[i] == diff)
        {
            i--;
            val++;
        }
        j = i;
        if (j == 1)
        {
            val++;
        }
        if (i - 2 >= 0 && a[i - 2] - a[i] == diff * 2)
        {
            i = i - 2;
            val += 2;
            while (i - 1 >= 0 && a[i - 1] - a[i] == diff)
            {
                i--;
                val++;
            }
        }
        ans = max(val + 1, ans);
    }

    reverse(a.begin(), a.end());

    i = n - 1;
    j = n - 1;
    while (j > 0)
    {
        i = j;

        int diff = a[i - 1] - a[i];
        int val = 0;
        while (i - 1 >= 0 && a[i - 1] - a[i] == diff)
        {
            i--;
            val++;
        }
        j = i;
        if (j == 1)
            val++;
        if (i - 2 >= 0 && a[i - 2] - a[i] == diff * 2)
        {
            i = i - 2;
            val += 2;
            while (i - 1 >= 0 && a[i - 1] - a[i] == diff)
            {
                i--;
                val++;
            }
        }
        ans = max(val + 1, ans);
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif