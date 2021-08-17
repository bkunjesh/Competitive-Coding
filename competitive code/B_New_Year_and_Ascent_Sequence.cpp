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
    vector<pair<int, int>> s;

    f(i, n)
    {
        int l, x;
        cin >> l;
        int first, last, prev, isvalid = 1;
        f(j, l)
        {
            cin >> x;

            if (j == 0)
            {
                prev = x;
                first = x;
                last = x;
                continue;
            }

            if (x > prev)
                isvalid = 0;

            prev = x;

            if (j == l - 1)
                last = x;
        }

        if (isvalid)
            s.push_back({last, first});
    }

    sort(s.begin(), s.end());

    int minus = 0;
    for (auto it : s)
    {
        minus += (s.end() - lower_bound(s.begin(), s.end(), pair<int, int>(it.S, -1)));
    }
    cout << n * n - minus << endl;
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