//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
// const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    int m, x;

    cin >> n >> m >> x;
    vector<pair<int, int>> a;
    vector<int> ans(n, 0);

    f(i, n) cin >> j, a.push_back({j, i});

    sort(a.begin(), a.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (i = n - 1; i >= n - m; i--)
    {
        q.push({a[i].F, n - i});
        //cout << a[i].S << " ";
        ans[a[i].S] = n - i;
    }

    for (i = 0; i < n - m; i++)
    {
        int p = q.top().F;
        int pile = q.top().S;
        q.pop();
        ans[a[i].S] = pile;
        q.push({a[i].F + p, pile});
    }

    vector<int> temp(m + 1);
    int mn = 1e9, mx = 0;
    while (!q.empty())
    {
        int p = q.top().F;
        int pile = q.top().S;
        //cout << pile << " ";
        q.pop();
        temp[pile] = p;
        mn = min(mn, p);
        mx = max(mx, p);
    }
    // sort(temp.begin() + 1, temp.end());

    if (mx - mn <= x)
    {
        cout << "YES" << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
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