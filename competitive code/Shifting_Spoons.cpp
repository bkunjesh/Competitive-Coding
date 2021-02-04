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
    set<pair<int, int>> a;
    int fpilesz;
    rep(i, n)
    {
        cin >> j;
        if (i == 1)
        {
            fpilesz = j;
            continue;
        }
        a.insert({j, i});
    }
    vector<tuple<int, int, int>> ans;
    for (auto it = a.begin(); it != a.end();)
    {
        auto cur = it;
        auto nxt = it;
        nxt++;
        auto curval = *cur;
        if (nxt == a.end())
        {
            if (curval.F > fpilesz)
            {
                cout << -1 << endl;
                return;
            }
        }

        auto nxtval = *nxt;
        if (curval.F > fpilesz)
        {
            a.insert({curval.F - fpilesz + nxtval.F, nxtval.S});
            ans.push_back({curval.S, nxtval.S, curval.F - fpilesz});
            ans.push_back({curval.S, 1, fpilesz});
            a.erase(nxt);
            fpilesz += fpilesz;
        }
        else
        {
            ans.push_back({curval.S, 1, curval.F});
            fpilesz += curval.F;
        }
        it++;
        a.erase(cur);
    }

    cout << ans.size() << endl;

    for (auto it : ans)
    {
        auto tpl = it;
        cout << get<0>(tpl) << " " << get<1>(tpl) << " " << get<2>(tpl) << endl;
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