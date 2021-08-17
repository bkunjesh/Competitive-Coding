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
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    auto uppersearch = [&](int x) {
        int l = 0, r = n, ans = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid == n)
                return mid;
            if (a[mid] > x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    };
    auto lowersearch = [&](int x) {
        int l = 0, r = n, ans = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid == n)
                return mid;
            if (a[mid] >= x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    };
    cin >> k;
    while (k--)
    {
        int p, q;
        cin >> p >> q;
        // cout << uppersearch(q) << " " << lowersearch(p) << endl;
        cout << uppersearch(q) - lowersearch(p) << " ";
    }

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