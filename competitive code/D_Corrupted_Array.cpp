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
    vector<int> a(n + 2);
    int sum = 0;
    f(i, n + 2) cin >> a[i], sum += a[i];

    sort(a.begin(), a.end());
    int cursum = sum - a[n + 1];

    for (i = 0; i <= n; i++)
    {
        if (cursum - a[i] == a[n + 1])
        {
            for (j = 0; j <= n; j++)
            {
                if (j == i)
                    continue;
                cout << a[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cursum = sum - a[n + 1] - a[n];
    if (a[n] == cursum)
    {
        f(i, n) cout << a[i] << " ";
        cout << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
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