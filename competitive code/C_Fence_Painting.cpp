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
const int N = 100005;

int n;
vector<int> g[N];
int a[100005], b[100005], c[100005], ans[100005];
map<int, set<int, greater<int>>> pos;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;

    pos.clear();

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i], ans[i] = -1, pos[c[i]].insert(i);

    int flag = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            if (pos[b[i]].empty())
            {
                flag = 1;
                break;
            }
            else
            {
                int index = *pos[b[i]].begin();
                pos[b[i]].erase(index);

                //	dbg(index);

                ans[index] = i;
            }
        }
    }

    if (ans[m] == -1)
    {
        int val = c[m];

        for (int i = 1; i <= n; i++)
        {

            if (b[i] == val)
            {

                ans[m] = i;

                break;
            }
        }
    }

    if (flag || ans[m] == -1)
    {
        cout << "NO" << endl;
    }
    else
    {

        int prev = ans[m];

        for (int i = m - 1; i >= 1; i--)
        {
            if (ans[i] == -1)
                ans[i] = prev;
            else
                prev = ans[i];
        }
        cout << "YES" << endl;

        for (int i = 1; i <= m; i++)
            cout << ans[i] << " ";
        cout << endl;
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