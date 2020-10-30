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
    int i, j, k;
    cin >> n;
    vector<tuple<int,int>> a;
    f(i, n) cin >> j,a.push_back({j,i+1});
    sort(a.begin(), a.end());
    auto root= a[0];
    auto end = a[n - 1];

    if (get<0>(root) == get<0>(end) && n > 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (i = n - 1; i > 0; i--)
    {
        if (get<0>(a[i]) == get<0>(root))
            break;
        cout << get<1>(root) << " " << get<1>(a[i]) << endl;
    }
    while (i > 0)
    {
        cout << get<1> (a[i])<< " " << get<1>(end)<< endl;
        i--;
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