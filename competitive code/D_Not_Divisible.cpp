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
const int N = 2000005;

int n;
vector<int> br(N);
void solve()
{
    int i, j, k, ans = 0;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    f(i, n)
    {
        if (br[a[i]]==0&&i < n - 1)
        {
            br[a[i]] = (a[i] == a[i + 1]) ? 1 : 0;
            if(br[a[i]])
            {
                for (j = a[i] * 2; j <= 1e6; j = j + a[i])
                    br[j] = 1;
            }
        }
        if (br[a[i]] == 0)
        {
            ans++;
            for (j = a[i] * 2; j <= 1e6; j = j + a[i])
                br[j] = 1;
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