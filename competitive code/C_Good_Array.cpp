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
const int N = 200005;

int n;

void solve()
{
    int i, j, k, sum = 0;

    cin >> n;
    vector<pair<int, int>> a;
    vector<int> ans;
    rep(i, n) cin >> j, sum += j, a.push_back({j, i});
    sort(a.begin(), a.end());
    for (i = 0; i < n - 1; i++)
    {
        int temp_sum = sum - a[i].F;
        if (temp_sum == 2 * a[n - 1].F)
        {
            ans.push_back(a[i].S);
        }
    }
    int temp_sum = sum - a[n - 1].F;
    if (temp_sum == 2 * a[n - 2].F)
    {
        ans.push_back(a[n - 1].S);
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