//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
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
    int i, j, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n+k);
    f(i, n) cin >> a[i], sum += a[i];
    sort(a.begin(), a.end(),greater<int>());
    // int x = sum / k;
    // int left = sum - x * k;
    // int leftlow = k - left;
    // int sumneed = extbowl * x;
    auto check = [&](int h)
    {
        int sum = 0;
        int extbowl = k - n;
        for (i = 0; i < n;i++)
        {
            if(a[i]>h)
            {
                sum += (a[i] - h);
            }
        }
        if(sum<h*extbowl)
            return 0;
        
    };

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