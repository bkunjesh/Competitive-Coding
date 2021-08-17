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

    int m;
    cin >> n >> m;
    vector<int> days[m + 1], visited(m + 1), ans(m + 1);
    rep(i, m)
    {
        cin >> k;
        while (k--)
        {
            cin >> j, days[i].push_back(j);
        }
    }
    vector<pair<int, int>> persons[n + 1];
    for (i = 1; i <= m; i++)
    {
        for (auto p : days[i])
        {
            persons[p].push_back({days[i].size(), i});
        }
    }
    rep(i, n) sort(persons[i].begin(), persons[i].end());
    rep(i, n)
    {
        k = (m+1) / 2;
        for (auto d : persons[i])
        {
            if (k == 0)
                break;
            if (!visited[d.S])
            {
                ans[d.S] = i;
                visited[d.S] = 1;
                k--;
            }
        }
    }

    rep(i, m) if (ans[i] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    rep(i, m) cout << ans[i] << " ";
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif