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

    int m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];
    vector<int> one, two;
    f(i, n)(b[i] == 1) ? one.push_back(a[i]) : two.push_back(a[i]);
    sort(one.begin(), one.end(), greater<int>());
    sort(two.begin(), two.end(), greater<int>());

    int curSumOne = 0;
    int r = (int)two.size();
    int curSumTwo = accumulate(two.begin(), two.end(), 0ll);
    int ans = INT_MAX;
    for (int l = 0; l <= one.size(); l++)
    {
        while (r > 0 && curSumOne + curSumTwo - two[r - 1] >= m)
        {
            r--;
            curSumTwo -= two[r];
        }
        if (curSumTwo + curSumOne >= m)
        {
            ans = min(ans, 2 * r + l);
        }
        if (l != one.size())
        {
            curSumOne += one[l];
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";

    // int sum = 0;
    // int ans = 0;
    // for (auto it : one)
    // {
    //     sum += it;
    //     ans++;
    //     if (sum >= m)
    //         break;
    // }
    // // cout << sum << " ";
    // if (sum < m)
    // {
    //     for (auto it : two)
    //     {
    //         sum += it;
    //         // cout << it << " ";
    //         ans += 2;
    //         if (sum >= m)
    //             break;
    //     }
    // }

    // cout << sum << " ";

    // if (sum >= m)
    //     cout << ans << endl;
    // else
    //     cout << -1 << endl;
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