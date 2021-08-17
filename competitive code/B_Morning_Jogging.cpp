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
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    vector<pair<int, int>> a; //{b(i,j),i} i->checkpoint_no
    // vector<map<int, int>> done;
    vector<vector<int>> done(m + 1, vector<int>(n + 1, 0));
    rep(i, n)
    {
        rep(j, m) cin >> b[i][j], a.push_back({b[i][j], i});
        sort(b[i].begin(), b[i].end());
    }
    sort(a.begin(), a.end());
    rep(i, m)
    {
        auto p = *a.begin();

        done[i][p.S] = p.F;
        a.erase(a.begin());
    }
    // rep(i,m)
    // {
    //     rep(j, n) cout << done[i][j] << " " ;
    //         cout << endl;
    // }

    while (a.size() > 0)
    {
        auto p = *a.begin();

        // cout << p.F << " " << p.S << " ";
        rep(i, m)
        {
            if (done[i][p.S] == 0)
            {
                // cout << i << " " << endl;
                done[i][p.S] = p.F;
                break;
            }
        }
        a.erase(a.begin());
    }

    rep(i, n)
    {
        rep(j, m)
        {
            cout << done[j][i] << " ";
        }
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif