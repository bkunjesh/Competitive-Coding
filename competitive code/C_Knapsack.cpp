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
    int i, j, k, w, sum = 0;

    cin >> n >> w;
    vector<pair<int, int>> a;
    rep(i, n)
    {
        cin >> j;
        if (j <= w)
            a.push_back({j, i});
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    if(a.size()>0)
    for (i = a.size() - 1; i >= 0; i--)
    {
        sum += a[i].F;
        ans.push_back(a[i].S);
        if (sum >= (w+1) / 2)
        {
            break;
        }
    }
    if (sum >= (w+1) / 2)
    {
        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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