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
    n = min(n, 4000ll);
    map<int, pair<int, int>> m;
    f(i, n)
    {
        for (j = i + 1; j < n; j++)
        {

            if (m.count(a[i] + a[j]) == 0)
                m[a[i] + a[j]] = make_pair(i, j);
            else
            {
                int u = m[a[i] + a[j]].F;
                int v = m[a[i] + a[j]].S;

                if (u != i && u != j && v != i && v != j)
                {
                    cout << "YES" << endl;
                    cout << u + 1 << " " << v + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif