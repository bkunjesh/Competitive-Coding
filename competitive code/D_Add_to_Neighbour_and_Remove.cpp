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
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1);
    f(i, n) cin >> a[i];

    int pref[n + 2];
    memset(pref, 0, sizeof(pref));

    pref[0] = a[0];
    rep(i, n - 1) pref[i] = pref[i - 1] + a[i];

    int sum = pref[n - 1];

    for (int len = n; len > 0; len--)
    {
        if (sum % len == 0)
        {
            int p = sum / len;
            int times = len;
            //cout << sum <<" "<<len<< endl;
            while (times-- && binary_search(pref, pref + n, p))
            {
                //cout << p << " ";
                p += p;
            }
           // cout << endl;
            if (times <= 0)
            {
                cout << n - len << endl;
                return;
            }
        }
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