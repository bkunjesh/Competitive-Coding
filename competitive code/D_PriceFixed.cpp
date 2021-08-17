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
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> ba; //(b,a);
    f(i, n) cin >> a[i] >> b[i], ba.push_back({b[i], a[i]});
    sort(ba.begin(), ba.end());
    f(i, n) a[i] = ba[i].S, b[i] = ba[i].F;
    i = 0, j = n - 1;
    int total = 0, ans = 0;
    while (i <= j)
    {
        
        if (b[i] <= total)
        {
            ans += a[i];
            total += a[i];
            a[i] = 0;
            i++;
        }
        else
        {
            
            int x = min(b[i]-total, a[j]);
            ans += (2 * x);
            total += x;
            a[j] -= x;
            if (a[j] == 0)
                j--;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif