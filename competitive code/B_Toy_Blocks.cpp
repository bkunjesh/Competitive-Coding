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
    int i, j, k, sum = 0, ans = 0, flag = 1;
    cin >> n;
    vector<int> a(n), diff(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    f(i, n)
    {
        diff[i] = a[n - 1] - a[i], sum += diff[i];
    }
    // if (flag)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    i = 0;
    //f(i, n)
    {
        int cursum = sum - diff[i];

        int curans;
        if(a[i]==cursum)
        {
            curans = 0;
        }
        else if (a[i] > cursum)
        {
            int temp = a[i] - cursum;
            curans = ((n - 1) - temp % (n - 1));
        }
        else
        {
            curans = cursum - a[i];
        }

        // cout << cursum << " ";
        // if ((cursum % (n - 2)) == 0)
        //     cursum = 0;
        ans = max(ans, curans);
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