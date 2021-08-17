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
    vector<int> a, b;
    f(i, n)
    {
        cin >> j;
        if (j % 2 == 0)
            a.push_back(j);
        else
            b.push_back(j);
    }
    int even = a.size();
    int odd = b.size();
    int ans = even * odd+even*(even-1)/2;
    
    for (i = 0; i < b.size(); i++)
    {
        for (j = i + 1; j < b.size(); j++)
        {
            if (__gcd(b[i], 2 * b[j]) > 1)
            {
                ans++;
            }
        }
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif