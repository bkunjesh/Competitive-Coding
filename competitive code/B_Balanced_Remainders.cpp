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
    int c[3] = {0};
    f(i, n) cin >> a[i], a[i] = a[i] % 3, c[a[i]]++;
    //cout << c[0] << " " << c[1] << " " << c[2] << " ";
    vector<pair<int, int>> s;
    s.push_back({c[0], 0});
    s.push_back({c[1], 1});
    s.push_back({c[2], 2});

    auto isEqual = [&]() {
        if (s[0].first == s[1].first && s[1].F == s[2].F)
            return 1;

        return 0;
    };
    int ans = 0;
    while (!isEqual())
    {
        sort(s.begin(), s.end());
        auto mx = s.back();
        s.pop_back();
        auto mn = s.front();
        s.erase(s.begin());
        //cout << mx.S << " " << mn.S << endl;

        ans += (mn.S - mx.S + 3) % 3;
        s.push_back({mx.F - 1, mx.S});
        s.push_back({mn.F + 1, mn.S});
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