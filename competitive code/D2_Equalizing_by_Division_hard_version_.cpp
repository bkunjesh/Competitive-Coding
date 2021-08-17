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
const int inf = 1e9;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    map<int, vector<int>> g;
    map<int, int> g_sum;
    f(i, n)
    {
        int cur = 0;
        j = 0;
        while (1)
        {
            int x = (a[i] / (1 << j));
            g[x].push_back(cur);            
            if(x==0)
                break;
            cur++, j++;
        }
        //g[(a[i] / (1 << j))].insert(cur);
    }

    int ans = inf;
    for (auto v : g)
    {
        j = 0;
        auto x = v.F;

        if (v.S.size() >= k)
        {
            sort(v.S.begin(), v.S.end());
            int sum = accumulate(v.S.begin(),v.S.begin()+k,0);
            ans = min(ans, sum);
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

