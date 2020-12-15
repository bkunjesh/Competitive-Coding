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
    vector<int> g[n + 1], visit(n + 1, 0), left;

    rep(i, n)
    {
        cin >> k;
        while (k--)
        {
            cin >> j;
            g[i].push_back(j);
        }
    }
    rep(i, n)
    {
        k = g[i].size();
        for (j = 0; j < k; j++)
        {
            if (visit[g[i][j]] == 0)
            {
                visit[g[i][j]] = 1;
                break;
            }
        }
        if (j >= k)
            left.push_back(i);
    }
    if (left.size() == 0)
    {
        cout << "OPTIMAL" << endl;
        return;
    }
    else
    {
        j = 1;
        cout << "IMPROVE" << endl;
        for (auto l : left)
        {
            while (visit[j] == 1 && j <= n)
                j++;
            cout << l << " " << j << endl;
            break;
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