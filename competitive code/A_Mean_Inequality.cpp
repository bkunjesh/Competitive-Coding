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
    f(i, 2 * n) cin >> a[i];
    sort(a.begin(), a.end());
    i = 0;
    j = n - 1;

    // int mid = j;
    vector<int> ans;
    while (i < n - 1 && j < 2 * n)
    {
        ans.push_back(a[j]);
        ans.push_back(a[i]);
        // cout << a[j] << " " << a[i] << " ";
        j++, i++;
    }
    while (j < 2 * n)
    {
        ans.push_back(a[j]);
        // cout << a[j] << " ";
        j++;
    }
    swap(ans[0], ans[2 * n - 1]);
    for(auto it:ans)
        cout << it << " ";
    cout << endl;

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