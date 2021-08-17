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

    int w, h;
    cin >> w >> h >> n;


    auto isGood = [&](int x) {
        int noOfRecInCol = x / h;
        int noOfRecInRow = x / w;
        if (noOfRecInRow * noOfRecInCol >= n)
            return 1;
        else
            return 0;
    };

    int low = 0, high = min(max(n * h, w), max(n * w, h)), ans ;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isGood(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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