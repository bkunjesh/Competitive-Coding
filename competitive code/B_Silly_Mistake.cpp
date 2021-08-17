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

map<int, int> visit;
vector<int> ans;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    j = -1;
    int in = 0, cnt = 0;
    set<int> s;

    for (i = 0; i < n; i++)
    {

        // cout << a[i] << " ";
        if (visit[abs(a[i])] == 0)
        {
            if (a[i] < 0)
            {
                cout << -1 << endl;
                return;
            }
            in++;
            cnt++;
            visit[a[i]]++;
            s.insert(a[i]);
            // cout << endl;
            continue;
        }
        if (a[i] > 0)
        {
            if (visit[a[i]] % 2==1 || s.find(a[i]) != s.end())
            {
                cout << -1 << endl;
                return;
            }

            visit[a[i]]++;
            s.insert(a[i]);
            in++;
            cnt++;
        }
        else
        {
            if (visit[(-a[i])] % 2==0)
            {
                cout << -1 << endl;
                return;
            }
            visit[(-a[i])]++;

            in--;
            cnt++;
        }
        // cout << " " << visit[abs(a[i])] << " " << in << " ";
        if (in == 0)
        {
            s.clear();
            ans.push_back(cnt);
            cnt = 0;
        }
        // cout << endl;
    }
    if (in != 0)
    {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

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