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
    vector<int> a(2 * n);

    unordered_map<int, int> mp, m;

    f(i, 2 * n) cin >> a[i], mp[a[i]]++;

    sort(a.begin(), a.end());

    vector<pair<int, int>> ans;

    for (i = 0; i < 2 * n - 1; i++)
    {
        m = mp;
        ans.clear();
        int sum = a[i] + a[2 * n - 1];
        int x = max(a[i], a[2 * n - 1]);
        ans.push_back({a[i], a[2 * n - 1]});
        m[a[i]]--, m[a[2 * n - 1]]--;
        for (j = 2 * n - 1; j >= 0; j--)
        {
            if(j==i) continue;
            if (m[a[j]] > 0)
            {
                if (m[x - a[j]] > 0)
                {
                    m[a[j]]--;
                    m[x - a[j]]--;
                    ans.push_back({x - a[j], a[j]});
                    x = max(x - a[j], a[j]);
                }
                else
                {
                    break;
                }
            }
        }
        if (j < 0)
        {
            m = mp;
            int flag = 1;
            for(auto it:ans)
            {
                m[it.F]--, m[it.S]--;
                if(m[it.F]<0||m[it.S]<0)
                {
                    flag = 0;
                }
            }
            if(flag){cout << "YES" << endl;
            cout << sum << endl;
            for (auto it : ans)
            {
                cout << it.F << " " << it.S << endl;
            }
            return;}
        }
    }
    cout << "NO" << endl;

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