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
int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n), m(2 * n + 1, 0), ans;
    f(i, n) cin >> a[i], m[a[i]] = 1;
    set<int> s;
    rep(i, 2 * n) if (m[i] == 0) s.insert(i);

    f(i, n)
    {
        auto it = s.upper_bound(a[i]);
        if (it == s.end())
        {
            cout << -1 << endl;
            return;
        }
        ans.push_back(min(a[i], *it));
        ans.push_back(max(a[i], *it));
        s.erase(it);
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

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