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
    set<pair<int, string>> q;
    map<int, string> m;

    auto search = [&](string s) {
        for (auto it : q)
        {
            if (it.S == s)
            {
                return it;
            }
        }
        // auto end = *q.end();
        return make_pair(-inf, s);
    };
    int mxval = 0;
    vector<pair<string, int>> a;
    f(i, n)
    {
        string s;
        cin >> s >> k;
        a.push_back({s, k});
        auto it = search(s);

        if (it.F == -inf)
        {
            q.insert({k, s});
            if (m[k] == "")
            {
                m[k] = s;
            }
        }
        else
        {
            int cur = it.F;
            q.erase(it);
            q.insert({k + cur, s});
            if (m[k + cur] == "")
            {
                m[k + cur] = s;
            }
        }
    }

    // cout << m[q.rbegin()->F] << endl;
    int mxscr = q.rbegin()->F;
    vector<string> maywin;
    for (auto it : q)
    {
        if (it.F == mxscr)
            maywin.push_back(it.S);
    }
    int erlytime = inf;
    string ans;
    for (auto str : maywin)
    {
        int temptime = 0, curscore = 0;

        for (auto it : a)
        {
            temptime++;
            if (it.F == str)
            {
                curscore += it.S;
                if (curscore >= mxscr)
                {
                    break;
                }
            }
        }
        if (erlytime > temptime)
        {
            erlytime = temptime;
            ans = str;
        }
    }

    cout << ans << endl;

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