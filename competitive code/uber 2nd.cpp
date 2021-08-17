//@ikung
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
// const int inf = 1e18;
const int N = 200005;

long long minimumTimeHire2021(vector<long long> d, vector<long long> b, long long p)
{
    // long long n = d.size();
    // long long k = b.size();
    // vector<long long> dleftOfP, bleftOfP, drightOfP, brightOfP;
    // long long ans = 0;
    // for (auto it : d)
    // {
    //     if (it < p)
    //         dleftOfP.push_back(it);
    //     else
    //         drightOfP.push_back(it);
    //     ans += (abs(p - it));
    // }
    // for (auto it : b)
    // {
    //     if (it < p)
    //         bleftOfP.push_back(it);
    //     else
    //         brightOfP.push_back(it);
    // }
    // if (dleftOfP.size() > bleftOfP.size())
    // {
    //     long long dleft = dleftOfP.size() - bleftOfP.size();
    //     sort(dleftOfP.begin(), dleftOfP.end(), greater<long long>());
    //     sort(brightOfP.begin(), brightOfP.end());
    //     for (long long i = 0; i < dleft; i++)
    //     {
    //         ans += (2 * (abs(brightOfP[i] - p)));
    //     }
    // }
    // else if (drightOfP.size() > brightOfP.size())
    // {
    //     long long dleft = drightOfP.size() - brightOfP.size();
    //     sort(drightOfP.begin(), drightOfP.end());
    //     sort(bleftOfP.begin(), bleftOfP.end(), greater<long long>());
    //     for (long long i = 0; i < dleft; i++)
    //     {
    //         ans += (2 * (abs(bleftOfP[i] - p)));
    //     }
    // }
    return ans;
}
void solve()
{
    long long i, j, k;
    long long p, n;
    cin >> n >> k >> p;
    vector<long long> d(n), b(k);
    f(i, n) cin >> d[i];
    f(i, k) cin >> b[i];
    cout << minimumTimeHire2021(d, b, p) << endl;

    return;
}

signed main()
{
    fast long long t = 1, i, j, k;
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
//#endifo