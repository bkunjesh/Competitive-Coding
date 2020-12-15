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
int dp[100005][2];
vector<int> arr[100000];

// 0 not heli
// 1 heli

void dfs(int node, int par)
{
    if (arr[node].size() == 1 || arr[node].size() == 0)
    {
        // leaf node and special case

        dp[1][node] = 1;
        return;
    }

    int val_1 = 0, val_2 = 0;

    // val_1 heli on node
    // val_2 heli not on node

    for (auto x : arr[node])
    {
        if (x == par)
            continue;
        dfs(x, node);

        val_2 += dp[1][x];

        val_1 += min(dp[0][x], dp[1][x]);
    }

    dp[0][node] = val_2;
    dp[1][node] = 1 + val_1;
}

void solve()
{
    int i, j, k, cnt = 0, x, y, p, z = 0;
    cin >> x;
    queue<int> que;

    if (x == 1)
    {
        que.push(x);
        // que.push(z);
        // z++;
    }
    while (!que.empty())
    {
        int sz = que.size();
        while (sz>0)
        {
            sz--;
            //int p = que.front();
            que.pop();
            cin >> y;
            for (i = 0; i < y; i++)
            {
                cin >> x;
                if (x == 1)
                {
                    que.push(x);
                    //que.push(z);

                    // arr[p].push_back(z);
                    // arr[z].push_back(p);
                    // z++;
                }
            }
        }
        cnt++;
    }

    cin >> p;
    if (cnt == 1 || cnt == 0)
    {
        if (cnt <= p)
            cout << cnt << " Mission Successful\n";
        else
            cout << cnt << " Mission Unsuccessful\n";
    }
    else if (cnt - 1 <= p)
    {
        cout << cnt - 1 << " Mission Successful\n";
    }
    else
        cout << cnt - 1 << " Mission Unsuccessful\n";

    // dfs(1, -1);

    // int ans = min(dp[1][1], dp[0][1]);
    // cout << ans << endl;

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