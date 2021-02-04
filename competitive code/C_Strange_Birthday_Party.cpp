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
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.F > b.F;
}
void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m;
    int a[n + 1], c[m + 1];
    map<int, int> mp;
    rep(i, n) cin >> a[i], mp[a[i]]++;
    rep(i, m) cin >> c[i];
    vector<pair<int, int>> vec;
    // cout << mp.size() << endl;
    for (auto it : mp)
    {
        vec.push_back({it.F, it.S});
    }
    sort(vec.begin(), vec.end(), comp);
    // cout << vec.size() << endl;
    int indsum = 0, ans = 0;
    int cnt = 1;
    for (auto it : vec)
    {
        // cout << it.F << " " << it.S << endl;

        if (indsum < it.F)
            while (indsum < it.F && it.S > 0)
            {
                //cout << a[cnt] << " ";
                ans += c[cnt++];
                indsum++;
                it.S--;
            }
        if (it.S > 0)
        {
            ans += (c[it.F] * it.S);
            it.S = 0;
        }

    }

    cout << ans << endl;

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