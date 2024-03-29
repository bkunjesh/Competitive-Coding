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
    vector<int> a(n);
    int sum = 0, mx = 0;
    f(i, n - 1) cin >> a[i], sum += a[i], mx = max(mx, sum);
    int first = n - mx;
    vector<int> ans;
    map<int, int> m;
    m[first] = 1;
    if (first <= 0 || first > n)
    {
        //cout << ans[1] << " ";
        cout << -1 << endl;
        return;
    }
    ans.push_back(first);
    f(i, n - 1)
    {
        if (ans.back() + a[i] <= 0 || ans.back() + a[i] > n || m[ans.back() + a[i]] != 0)
        {
            //cout << ans[1] << " ";
            cout << -1 << endl;
            return;
        }
        m[ans.back() + a[i]] = 1;
        ans.push_back(ans.back() + a[i]);
    }
    for (auto it : ans)
        cout << it << " ";

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